// Problem #    : 494
// Title        : Kindergarten Counting Game
// Accepted     : Yes
// Date         : 20180519

#include <algorithm>
#include <assert.h>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <utility>
#include <vector>

using namespace std;

typedef vector<vector<int>> vec2d;
typedef vector<int> vi;
typedef pair<int, int> ii;

bool isLetter(char c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int main() {

  string line;
  while (getline(cin, line) && line != "") {

    stringstream ss(line);

    char c;

    // true if last character was a letter
    bool l = false;
    int word_count = 0;
    while (ss.get(c)) {

      if (isLetter(c) && !l) {
        l = true;
      } else if (!isLetter(c) && l) {
        word_count++;
        l = false;
      }

      // if (isLetter(c)) {
      //   if (l) {
      //     // c is letter, and last was letter
      //     // ==> do nothing
      //   } else {
      //     // c is letter, but last was not a letter
      //     // ==> update last to true
      //     l = true;
      //   }
      // } else {
      //   if (l) {
      //     // c is not a letter, but last was a letter
      //     // +1 word, update last to false
      //     word_count++;
      //     l = false;
      //   } else {
      //     // c is not a letter, and last was not a letter
      //     // ==> do nothing
      //   }
      // }
    }

    // special case: handle when last was a letter ==> +1 word
    if (l) {
      word_count++;
    }

    cout << word_count << endl;
  }

  return 0;
}
