// Problem #    : 455
// Created on   : 2018-07-18 20:16:16

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

typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints
typedef vector<vii> vvii;  // 2d vector of pairs
typedef vector<bool> vb;   // 1d vector of bools
typedef long long ll;

// Call this first, before call to 'kmp'.  This serves as an important
// initialization step.
// 'p' is the PATTERN you wish to search for in a given string.
// 'v' is not important outside the implementation of kmpInit and kmp
void kmpInit(const string &p, vi &v) {
  int len = p.length();
  v.assign(len + 1, -1);
  for (int i = 1; i <= len; i++) {
    int j = v[i - 1];
    while (j != -1 && p[j] != p[i - 1])
      j = v[j];
    v[i] = j + 1;
  }
}

// 's' is the string we are searching for pattern 'p' in.
// 'v' is the initialized table, (caller needs to call kmpInit just prior to
// calling this function), and 'res' is a vector of indices, where each index
// marks the 0-based position of a match of 'p' in 's'
void kmp(const string &s, const string &p, vi &v, vi &res) {
  int i = 0, j = 0, sl = s.length(), pl = p.length();
  while (i < sl) {
    while (j != -1 && (j == pl || p[j] != s[i]))
      j = v[j];
    i++;
    j++;
    if (j == pl) {
      res.push_back(i - pl);
      j = v[j];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    // In this particular problem, we are looping because we need to
    // find all matches of 'p' in 's', where 'p' is the prefix string of
    // 's', of length 'i'.  This part is problem specific.
    for (int i = 1; i <= (int)s.length() / 2; i++) {
      string p = s.substr(0, i);

      // Since we want ALL the matches, we can use 'res' to store them.
      // Note: need to call kmpInit before kmp
      vi v, res;
      kmpInit(p, v);
      kmp(s, p, v, res);

      // find period
      // i = length of pattern
      // res = arr of first character where match occurs
      int k = 0;
      for (auto &j : res) {
        if (k != j) {
          break;
        }
        k += i;
      }
      if (k == (int)s.length()) {
        cout << i << endl;
        goto next;
      }
    }
    cout << s.length() << endl;
  next:;
    if (t)
      cout << endl;
  }

  return 0;
}