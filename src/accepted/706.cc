// Problem #    : 706
// Created on   : 2018-06-03 23:06:56

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// e.g. int varX = 376; what_is(varX); prints "varX is 376"
// e.g. what_is(varX * 2 + 1); prints "varX * 2 + 1 is 753"
#define what_is(x) cerr << #x << " is " << x << endl;

// e.g. rep(i, 1, 10) is 1, 2, ..., 8, 9 and rep(i, 10, 1) is 9, 8, ..., 2, 1
#define rep(i, begin, end)                            \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

typedef vector<vector<int>> vec2d;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
bool isPalidrome(string s) {
  return equal(s.begin(), next(s.begin(), s.size() / 2), s.rbegin());
}

int n, s;

int lit[][7] = {{1, 1, 1, 0, 1, 1, 1}, {0, 0, 1, 0, 0, 1, 0},
                {1, 0, 1, 1, 1, 0, 1}, {1, 0, 1, 1, 0, 1, 1},
                {0, 1, 1, 1, 0, 1, 0}, {1, 1, 0, 1, 0, 1, 1},
                {1, 1, 0, 1, 1, 1, 1}, {1, 0, 1, 0, 0, 1, 0},
                {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> s >> n) {
    if (n == 0 && s == 0) break;

    // cout << "n, s = " << n << ", " << s << endl;

    string digits = to_string(n);

    for (int i = 0; i < 2 * s + 3; i++) {
      int b = -1;
      if (i == 0) {
        b = 0;
      } else if (i == (2 * s + 3) / 2) {
        b = 3;
      } else if (i == (2 * s + 3) - 1) {
        b = 6;
      } else if (i < (2 * s + 3) / 2) {
        b = 1;
      } else if (i < (2 * s + 3) - 1) {
        b = 4;
      } else {
        exit(1);
      }

      for (int j = 0; j < (int)digits.length(); j++) {
        int c = (int)(digits[j] - '0');
        // cout << "c:" << c << endl;
        if (b == 0 || b == 3 || b == 6) {
          cout << " ";
          if (lit[c][b]) {
            cout << string(s, '-');
          } else {
            cout << string(s, ' ');
          }
          cout << " ";
        } else {
          if (lit[c][b])
            cout << "|";
          else
            cout << " ";
          cout << string(s, ' ');
          if (lit[c][b + 1])
            cout << "|";
          else
            cout << " ";
        }
        if (j < (int)digits.length() - 1)
          cout << " ";
        else
          cout << "\n";
      }
    }
    cout << "\n";
  }

  return 0;
}
