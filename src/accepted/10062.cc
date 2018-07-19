// Problem #    : 10062
// Created on   : 2018-07-18 19:00:56

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string l;
  int tc = 1;
  while (getline(cin, l)) {
    if (tc > 1)
      cout << endl;
    tc++;
    vector<int> v(130, 0);
    for_each(l.begin(), l.end(), [&](char c) {
      if (c <= 127 && c >= 32)
        v[c] += 1;
    });
    vector<ii> s;
    for (int i = 0; i < 130; i++) {
      if (v[i]) {
        s.push_back(ii(v[i], i));
      }
    }
    sort(s.begin(), s.end(), [](ii x, ii y) {
      return (x.first < y.first || (x.first == y.first && x.second > y.second));
    });

    for (auto &i : s) {
      cout << i.second << " " << i.first << endl;
    }
  }

  return 0;
}
