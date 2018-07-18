// Problem #    : 10323
// Created on   : 2018-07-17 17:37:43

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

#define sz(a) (int)a.size()

typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints
typedef vector<vii> vvii;  // 2d vector of pairs
typedef vector<bool> vb;   // 1d vector of bools
typedef long long ll;

ostream &operator<<(ostream &os, ii &p) {
  os << "(" << p.first << ", " << p.second << ")\n";
}

ostream &operator<<(ostream &os, vi &v) {
  for (auto &i : v)
    os << i << " ";
  os << endl;
}
ostream &operator<<(ostream &os, vector<char> &v) {
  for (auto &i : v)
    os << i << " ";
  os << endl;
}

ll f[1000] = {0};

// ll fib(int n) {
//   if (n < 2)
//     return (f[n] = n);

//   if (f[n])
//     return f[n];

//   int k = (n & 1) ? (n + 1) / 2 : n / 2;

//   f[n] = (n & 1) ? fib(k - 1) * fib(k - 1) + fib(k) * fib(k)
//                  : (2 * fib(k - 1) + fib(k)) * fib(k);

//   return f[n];
// }

ll fac(ll n) {
  if (n < 2)
    return (f[n] = 1);

  if (f[n])
    return f[n];

  f[n] = fac(n - 1) * n;

  return f[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // for (int i = 0; i < 20; i++) {
  //   cout << i << " : " << fac(i) << endl;
  // }

  int n;
  while (cin >> n) {

    if (n < 0 && (n & 1)) {
      cout << "Overflow!\n";
    } else if (n < 8) {
      cout << "Underflow!\n";
    } else if (n > 13) {
      cout << "Overflow!\n";
    } else {
      cout << fac(n) << endl;
    }
  }

  return 0;
}
