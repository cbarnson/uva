// Problem #    : 10699
// Created on   : 2018-07-21 19:52:29

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

ll sz;
vi primes;
bitset<10000010> p;

void sieve(ll m) {
  sz = m + 1;
  p.set();
  p[0] = p[1] = 0;
  for (ll i = 2; i <= sz; i++) {
    if (p[i]) {
      for (ll j = i * i; j <= sz; j += i) {
        p[j] = 0;
      }
      primes.push_back((int)i);
    }
  }
}

ll primeFactors(ll n) {
  ll s = 0, i = 0, pf = primes[i];
  while (pf * pf <= n) {
    if (n % pf == 0)
      s++;
    while (n % pf == 0) {
      n /= pf;
    }
    pf = primes[++i];
  }
  if (n != 1) {
    s++;
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve(1000000);
  int n;
  while (cin >> n) {
    if (n == 0) {
      break;
    }

    cout << n << " : " << primeFactors(n) << endl;
  }

  return 0;
}
