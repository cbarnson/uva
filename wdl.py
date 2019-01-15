#!/usr/bin/env python

# Python 2->3 libraries that were renamed.
try:
    from urllib2 import urlopen
except:
    from urllib.request import urlopen
try:
    from HTMLParser import HTMLParser
except:
    from html.parser import HTMLParser

# Other libraries.
from sys import argv
from subprocess import call
from functools import partial, wraps
import re
 
# User modifiable constants:
TEMPLATE='default_cf.cc'
COMPILE_CMD='g++ -g -std=c++11 -Wall $DBG'
SAMPLE_INPUT='in'
SAMPLE_OUTPUT='out'
MY_OUTPUT='my_output'

# Do not modify these!
RED_F='\033[31m'
GREEN_F='\033[32m'
BOLD='\033[1m'
NORM='\033[0m'
TIME_CMD='`which time` -o time.out -f "(%es)"'
TIME_AP='`cat time.out`'

# Problems parser.
class CodeforcesSingleProblemParser(HTMLParser):

    # def __init__(self, folder):
    def __init__(self, problem, letter):
        print('init...')
        HTMLParser.__init__(self)
        self.problem = problem
        self.letter = letter
        self.num_tests = 0
        self.testcase = None
        self.start_copy = False
        print('...init done')
    
    def handle_starttag(self, tag, attrs):
        print('handle_starttag')
        if tag == 'div':
            if attrs == [('class', 'input')]:
                self.num_tests += 1
                self.testcase = open(
                    '%d.%s' % (self.num_tests, SAMPLE_INPUT), 'w')
            elif attrs == [('class', 'output')]:
                self.testcase = open(
                    '%d.%s' % (self.num_tests, SAMPLE_OUTPUT), 'w')
        elif tag == 'pre':
            if self.testcase != None:
                self.start_copy = True
 
    def handle_endtag(self, tag):
        print('handle_endtag')
        if tag == 'br':
            if self.start_copy:
                self.testcase.write('\n')
                self.end_line = True
        if tag == 'pre':
            if self.start_copy:
                if not self.end_line:
                    self.testcase.write('\n')
                self.testcase.close()
                self.testcase = None
                self.start_copy = False
    
    def handle_entityref(self, name):
        print('handle_entityref')
        if self.start_copy:
            self.testcase.write(self.unescape(('&%s;' % name)))
 
    def handle_data(self, data):
        print('handle_data')
        if self.start_copy:
            self.testcase.write(data)
            self.end_line = False


# Problems parser.
class CodeforcesProblemParser(HTMLParser):

    def __init__(self, folder):
        HTMLParser.__init__(self)
        self.folder = folder
        self.num_tests = 0
        self.testcase = None
        self.start_copy = False
    
    def handle_starttag(self, tag, attrs):
        if tag == 'div':
            if attrs == [('class', 'input')]:
                self.num_tests += 1
                self.testcase = open(
                    '%s/%s%d' % (self.folder, SAMPLE_INPUT, self.num_tests), 'w')
            elif attrs == [('class', 'output')]:
                self.testcase = open(
                    '%s/%s%d' % (self.folder, SAMPLE_OUTPUT, self.num_tests), 'w')
        elif tag == 'pre':
            if self.testcase != None:
                self.start_copy = True
 
    def handle_endtag(self, tag):
        if tag == 'br':
            if self.start_copy:
                self.testcase.write('\n')
                self.end_line = True
        if tag == 'pre':
            if self.start_copy:
                if not self.end_line:
                    self.testcase.write('\n')
                self.testcase.close()
                self.testcase = None
                self.start_copy = False
    
    def handle_entityref(self, name):
        if self.start_copy:
            self.testcase.write(self.unescape(('&%s;' % name)))
 
    def handle_data(self, data):
        if self.start_copy:
            self.testcase.write(data)
            self.end_line = False

# Contest parser.  
class CodeforcesContestParser(HTMLParser):

    def __init__(self, contest):
        HTMLParser.__init__(self)
        self.contest = contest
        self.start_contest = False
        self.start_problem = False
        self.name = ''
        self.problem_name = ''
        self.problems = []
        self.problem_names = []
    
    def handle_starttag(self, tag, attrs):
        if self.name == '' and attrs == [('style', 'color: black'), ('href', '/contest/%s' % (self.contest))]:
                self.start_contest = True
        elif tag == 'option':
            if len(attrs) == 1:
                regexp = re.compile(r"u'[A-Z].*'")
                string = str(attrs[0])
                search = regexp.search(string)
                if search is not None:
                    self.problems.append(search.group(0).split("'")[-2])
                    self.start_problem = True
 
    def handle_endtag(self, tag):
        if tag == 'a' and self.start_contest:
            self.start_contest = False
        elif self.start_problem:
            self.problem_names.append(self.problem_name)
            self.problem_name = ''
            self.start_problem = False
 
    def handle_data(self, data):
        if self.start_contest:
            self.name = data
        elif self.start_problem:
            self.problem_name += data
        




# (CB) Parses a singple problem page for this contest
def parse_single_problem(problem, letter):
    print('in parse_single_problem, problem: %s, letter %s' % (problem, letter))
    # url = 'http://codeforces.com/contest/%s/problem/%s' % (contest, problem)
    url = 'http://codeforces.com/problemset/problem/%s/%s' % (problem, letter)
    print('url: %s' % (url))
    html = urlopen(url).read()
    parser = CodeforcesSingleProblemParser(problem, letter)
    parser.feed(html.decode('utf-8')) 
    # .encode('utf-8') Should fix special chars problems?
    return parser.num_tests




# Parses each problem page.
# def parse_problem(folder, contest, problem):
#     url = 'http://codeforces.com/contest/%s/problem/%s' % (contest, problem)
#     html = urlopen(url).read()
#     parser = CodeforcesProblemParser(folder)
#     parser.feed(html.decode('utf-8')) 
#     # .encode('utf-8') Should fix special chars problems?
#     return parser.num_tests

# Parses the contest page.  
# def parse_contest(contest):
#     url = 'http://codeforces.com/contest/%s' % (contest)
#     html = urlopen(url).read()
#     parser = CodeforcesContestParser(contest)
#     parser.feed(html.decode('utf-8'))
#     return parser

# Generates the test script.
# def generate_test_script(folder, num_tests, problem):
#     with open(folder + 'test.sh', 'w') as test:
#         test.write(
#             ('#!/bin/bash\n'
#             'DBG=""\n'
#             'while getopts ":d" opt; do\n'
#             '  case $opt in\n'
#             '    d)\n'
#             '      echo "-d was selected; compiling in DEBUG mode!" >&2\n'
#             '      DBG="-DDEBUG"\n'
#             '      ;;\n'
#             '    \?)\n'
#             '      echo "Invalid option: -$OPTARG" >&2\n'
#             '      ;;\n'
#             '  esac\n'
#             'done\n'
#             '\n'
#             'echo Compiling...\n'
#             'if ! '+COMPILE_CMD+' {0}.cc; then\n'
#             '    exit\n'
#             'fi\n'
#             'INPUT_NAME='+SAMPLE_INPUT+'\n'
#             'OUTPUT_NAME='+SAMPLE_OUTPUT+'\n'
#             'MY_NAME='+MY_OUTPUT+'\n').format(problem))
#         test.write(
#             'for test_file in $INPUT_NAME*\n'
#             'do\n'
#             '    i=$((${{#INPUT_NAME}}))\n'
#             '    test_case=${{test_file:$i}}\n'
#             '    rm -R $MY_NAME* 2> /dev/null\n'
#             '    if ! {5} ./a.out < $INPUT_NAME$test_case > $MY_NAME$test_case; then\n'
#             '        echo {1}{4}Sample test \#$test_case: Runtime Error{2} {6}\n'
#             '        echo ========================================\n'
#             '        echo Sample Input \#$test_case\n'
#             '        cat $INPUT_NAME$test_case\n'
#             '    else\n'
#             '        if diff --brief $MY_NAME$test_case $OUTPUT_NAME$test_case > /dev/null; then\n'
#             '            echo {1}{3}Sample test \#$test_case: Accepted{2} {6}\n'
#             '        else\n'
#             '            echo {1}{4}Sample test \#$test_case: Wrong Answer{2} {6}\n'
#             '            echo ========================================\n'
#             '            echo Sample Input \#$test_case\n'
#             '            cat $INPUT_NAME$test_case\n'
#             '            echo ========================================\n'
#             '            echo Sample Output \#$test_case\n'
#             '            cat $OUTPUT_NAME$test_case\n'
#             '            echo ========================================\n'
#             '            echo My Output \#$test_case\n'
#             '            cat $MY_NAME$test_case\n'
#             '            echo ========================================\n'
#             '        fi\n'
#             '    fi\n'
#             '    rm -R $MY_NAME* 2> /dev/null\n'
#             'done\n'
#             .format(num_tests, BOLD, NORM, GREEN_F, RED_F, TIME_CMD, TIME_AP))
#     call(['chmod', '+x', folder + 'test.sh'])

from pathlib import Path
import datetime

# Main function. 
def main():
    # only downloading for 1 single problem
    if(len(argv) < 3):
        print('USAGE: ./wdl.py 512 A')
        return
    problem = argv[1]
    letter = argv[2]
    ext = '.py'
    target = "%s%s%s" % (problem, letter, ext)

    print('Target codeforces problem: %s' % target)
    x = parse_single_problem(problem, letter)

    # template = Path('default_cf.py')
    # if (template.exists() and template.is_file()):
    #     call('cp -n %s %s' % (template, target), shell=True)
    #     call('')

    # print('Creating  template problem %s...' % (target))    

    # cppTemplate = Path(TEMPLATE)
    # targetCpp = target + '.cc'
    # if (cppTemplate.exists() and cppTemplate.is_file()):
    #     print('Copying...')
    #     call('cp -n %s %s' % (TEMPLATE, targetCpp), shell=True)
    #     # call(['cp', '-n', TEMPLATE, '%s' % (targetCpp)])
    #     call("ls")
    #     print('Adding header...')
    #     line1 = '// Created on : {:%Y-%b-%d %H:%M:%S}'.format(datetime.datetime.now())
    #     call("echo %s | cat - %s > tmp && mv tmp %s" % (line1, targetCpp, targetCpp), shell=True)
    #     # call("cat %s" % (targetCpp))
    #     # line2 = '// Problem \#    : %s' % (target)
    #     print('targetCpp = %s' % targetCpp)
    #     line2='// Problem \#\ \ : %s' % target
    #     call("echo %s | cat - %s > tmp && mv tmp %s" % (line2, targetCpp, targetCpp), shell=True)
    #     call("cat %s" % (targetCpp), shell=True)

    # else:
    #     print('ERROR, could not locate C++ Template.  Exiting...')
    #     exit()

    # print('All done!')

    
    # Find contest and problems.
    # print ('Parsing contest %s, please wait...' % contest)
    # content = parse_contest(contest)
    # print (BOLD+GREEN_F+'*** Round name: '+content.name+' ***'+NORM)
    # print ('Found %d problems!' % (len(content.problems)))
    
    # # Find problems and test cases.
    # for index, problem in enumerate(content.problems):
    #     print ('Downloading Problem %s: %s...' % (problem, content.problem_names[index]))
    #     folder = '%s/%s/' % (contest, problem)
    #     call(['mkdir', '-p', folder])
    #     call(['cp', '-n', TEMPLATE, '%s/%s/%s.cc' % (contest, problem, problem)])
    #     num_tests = parse_problem(folder, contest, problem)
    #     print('%d sample test(s) found.' % num_tests)
    #     generate_test_script(folder, num_tests, problem)
    #     print ('========================================')
        
    # print ('Use ./test.sh to run sample tests in each directory.')
 
if __name__ == '__main__':
    main()
    
