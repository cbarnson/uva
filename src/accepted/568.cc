// Problem #    : 568
// Created on   : 2018-07-17 19:56:53

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

ll last2(ll n) {
  if (n == 0)
    return 0;
  while (n % 10 == 0) {
    n /= 10;
  }
  return n % 1000000;
}

int last1(int n) {
  if (n == 0)
    return 0;
  while (n % 10 == 0) {
    n /= 10;
  }
  return n % 10;
}

ll f[10005] = {0};

ll fac(ll n) {
  if (n < 2)
    return (f[n] = 1);

  if (f[n])
    return f[n];

  f[n] = last2(n * fac(n - 1));
  return f[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n) {
    cout << setw(5) << right << n;
    cout << " -> ";
    cout << last1(fac(n)) << endl;
  }

  return 0;
}
