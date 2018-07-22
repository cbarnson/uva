// Problem #    : sieve
// Created on   : 2018-07-21 14:02:14

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

bool isPrime(ll x) {
  if (x <= sz)
    return p[x];
  for (int i = 0; i < (int)primes.size(); i++)
    if (x % primes[i] == 0)
      return false;
  return true;
}

vi primeFactors(ll n) {
  vi s;
  ll i = 0, pf = primes[i];
  while (pf * pf <= n) {
    while (n % pf == 0) {
      n /= pf;
      s.push_back(pf);
    }
    pf = primes[++i];
  }
  if (n != 1)
    s.push_back(n);
  return s;
}

vi uniquePrimeFactors(ll n) {
  vi s;
  ll i = 0, pf = primes[i];
  while (pf * pf <= n) {
    if (n % pf == 0) {
      s.push_back(pf);
      n /= pf;
    }
    while (n % pf == 0) {
      n /= pf;
    }
    pf = primes[++i];
  }
  if (n != 1) {
    s.push_back(n);
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve(1000000);

  vi uniquePF = uniquePrimeFactors(18);
  vi allPF = primeFactors(18);

  cout << "unique  : " << uniquePF;
  cout << "pfactors: " << allPF;

  return 0;
}
