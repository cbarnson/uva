<!-- ![Logo of the project](https://raw.githubusercontent.com/jehna/readme-best-practices/master/sample-logo.png) -->

# Competitive Programming
> UVa, CodeForces, and more

This repository was originally for UVa Online Judge solutions, but has expanded to encompass all things competitive programming.  There's a healthy supply of CodeForces solutions, primarily in C++, but also some Python, and even Java.  I've also used this repository as a space to collect useful code snippets, algorithms, and tricks that are worth having around.

## Getting started

Most C++ programs you'll find in this repository are standalone, single-file.  Most competitive programming contests and sites offer GNU GCC, so that's generally what we want to build with.  But you *always* want to use the same compiler as the judging system you'll be submitting against, so don't just fire up your Visual Studio IDE without a second thought.  Problems are meant to be solved in a contest-setting, which means (ideally) your code is relatively short, and certainly a single source file.   Most people opt for a lighter editor like [Emacs](https://www.gnu.org/software/emacs/), [Vim](https://www.vim.org/), or [VS Code](https://code.visualstudio.com/).  

### Compile / debugging

Compilation is almost always the same (see below), and you run your executable with input being piped in from a file, e.g. `./solution.exe < input.txt`, and output to standard out (redirect to file with `./solution.exe < input.txt > output.txt`).

I use several helper scripts to make this process of setup, testing, comparing, and (finally) submitting a little bit easier.  These scripts constitute a variety of `bash`, `sh`, `batch`, and `python` files.  The ones I use often are probably scattered about in the root of this workspace, and others have been archived to `/archives/scripts`.  Have a look, hopefully you'll find something that works.

On Windows, I've recently enjoyed using [MSYS2](http://www.msys2.org/) since you get `pacman`.  But you can also try [Cygwin](https://www.cygwin.com/), or you can download [MinGW-64](https://mingw-w64.org) and use a MinTTY emulator like [Git-bash](https://gitforwindows.org/).  On Linux, just use whatever you have, as `GCC` is pretty universally accessible (on new setups of say, Ubuntu for example, you may need to run `sudo apt-get install build-essential`).

Once you're all setup, with your solution contained in a single C++ source file like `main.cc` file ready to go, compile with:

```shell
g++ -std=c++17 -Wall main.cc -o main.exe
```

### Submission (CodeForces)

Lets say you are solving problem `1102E` on CodeForces ([here](https://codeforces.com/problemset/problem/1102/E)).  You want to submit.  From the problem page, on the side bar *select the language* and compiler:

<img src="res/codeforces-submit.png">

### Submission (UVa Online Judge)

Lets say you are solving problem `137` on UVa ([here](https://uva.onlinejudge.org/external/1/137.pdf)).  You want to submit.  From the main site: https://uva.onlinejudge.org/, login, and navigate to "Quick Submissions" on the side bar.  From here, choose your compiler and either paste in your code or upload the source file. 

<img src="res/uva-submit.png">

<!-- ### Initial Configuration

Some projects require initial configuration (e.g. access tokens or keys, `npm i`).
This is the section where you would document those requirements. -->

<!-- ## Developing

Here's a brief intro about what a developer must do in order to start developing
the project further:

```shell
git clone https://github.com/cbarnson/project.git
```

And state what happens step-by-step. -->

<!-- ### Building

If your project needs some additional steps for the developer to build the
project after some code changes, state them here:

```shell
./configure
make
make install
```

Here again you should state what actually happens when the code above gets
executed. -->

<!-- ### Deploying / Publishing

In case there's some step you have to take that publishes this project to a
server, this is the right time to state it.

```shell
packagemanager deploy awesome-project -s server.com -u username -p password
```

And again you'd need to tell what the previous code actually does. -->


<!-- ## Bad/incorrect UVA problem statements

- 459

## Tools and Extensions

- UVa Online Judge Chrome web extension (https://chrome.google.com/webstore/detail/uva-quick-access-tool/ohmmnbcombfdichbnnlhkijfdmkgllhe)

### VS Code Extensions

- https://github.com/lucastan/uva-node

#### uva-node

Useful commands:

- view 123
- send 123
- stat
- tpl show

Command to add UVA account:

- `add uva barnsoc4 <password>`

Command to set user account to default:

- `use uva barnsoc4` or `use`

Command to show user accounts

- `show`

If you need to install:

- clone repo `git clone https://github.com/lucastan/uva-node.git`
- install globally with `npm install -g uva-node`

To update:

- do `git pull` in the uva-node directory

# Build and Test

Each UVa problem is contained by a single _.cc/_.cpp file, where the file name is the problem ID. Typical compiler used in competition is GCC, and a typical compile operation would look like the following:

```
g++ -std=c++11 123.cc -Wall -o 123
```
 -->


<!-- ## Features

What's all the bells and whistles this project can perform?
* What's the main functionality
* You can also do another thing
* If you get really randy, you can even do this

## Configuration

Here you should write what are all of the configurations a user can enter when
using the project.

#### Argument 1
Type: `String`  
Default: `'default value'`

State what an argument does and how you can use it. If needed, you can provide
an example below.

Example:
```bash
awesome-project "Some other value"  # Prints "You're nailing this readme!"
```

#### Argument 2
Type: `Number|Boolean`  
Default: 100

Copy-paste as many of these as you need.

## Contributing

If you'd like to contribute, please fork the repository and use a feature
branch. Pull requests are welcome. -->

## Links

### Online judging systems and problem databases

### Online judges

- UVa Online Judge: https://uva.onlinejudge.org/, [uHunt](https://uhunt.onlinejudge.org/), [Live Archive](https://icpcarchive.ecs.baylor.edu/)
- CodeForces: https://codeforces.com/, [Code drills](https://code-drills.com), [CodeForces Visualizer](https://cfviz.netlify.com/)
- Kattis: https://www.kattis.com/

### Past contests

- North America Qualifier (NAQ): [2018](https://open.kattis.com/contests/naq18open)
- Alberta Collegiate Programming Contest (ACPC): [2017](https://acpc17.kattis.com/standings), [2018](https://acpc18.kattis.com/standings)
- Rocky Mountain Regional Contest (RMRC): [2013](https://open.kattis.com/problem-sources/Rocky%20Mountain%20Regional%20Contest%20%28RMRC%29%202013), [2014](https://open.kattis.com/problem-sources/Rocky%20Mountain%20Regional%20Contest%20%28RMRC%29%202014), [2015](https://open.kattis.com/problem-sources/Rocky%20Mountain%20Regional%20Contest%20%28RMRC%29%202015), [2016](https://open.kattis.com/problem-sources/Rocky%20Mountain%20Regional%20Contest%20%28RMRC%29%202016), [2017](https://open.kattis.com/problem-sources/Rocky%20Mountain%20Regional%20Contest%20%28RMRC%29%202017), [2018](https://open.kattis.com/problem-sources/Rocky%20Mountain%20Regional%20Contest%20%28RMRC%29%202018)

### Learning

- GeeksforGeeks: https://www.geeksforgeeks.org/
- C++17 Features: https://medium.com/@afinlay/new-language-features-language-changes-in-c-17-7e953ff64c65
- C++17, competitive programming edition: https://codeforces.com/blog/entry/57729
- Graph Algorithms: https://codeforces.com/blog/entry/16221?locale=en
- Everything about dynamic programming: https://codeforces.com/topic/43366/en4
- Awesome Competitive Programming: http://codeforces.com/blog/entry/23054


<!-- Even though this information can be found inside the project on machine-readable
format like in a .json file, it's good to include a summary of most useful
links to humans using your project. You can include links like:

- Project homepage: https://your.github.com/awesome-project/
- Repository: https://github.com/your/awesome-project/
- Issue tracker: https://github.com/your/awesome-project/issues
  - In case of sensitive bugs like security vulnerabilities, please contact
    my@email.com directly instead of using issue tracker. We value your effort
    to improve the security and privacy of this project!
- Related projects:
  - Your other project: https://github.com/your/other-project/
  - Someone else's project: https://github.com/someones/awesome-project/ -->


## Licensing

The code in this project is licensed under MIT license.

The MIT License (MIT)

Copyright (c) 2019 C. Barnson

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.