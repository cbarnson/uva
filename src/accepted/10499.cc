// Problem #    : 10499
// Created on   : 2018-07-21 20:52:19

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

ostream &operator<<(ostream &os, vi &v) {
  for (auto &i : v)
    os << i << " ";
  os << endl;
}

int numer(int n) { return 4 + n; }
// int numer(int n) { return 4 + ((n > 2) ? n : 2); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n) {
    if (n < 0) {
      return 0;
    }
    double f;
    if (n > 1) {
      double num = (double)numer(n);
      f = (double)(n)*100.0 / 4.0;
    } else {
      f = 0.0;
    }

    // ll x = f * 100;
    // cout << x << "%" << endl;
    cout << setprecision(0) << fixed << f << "%" << endl;
  }

  return 0;
}
