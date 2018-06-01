// Problem #    : 686
// Created on   : 2018-05-31 22:46:18

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

typedef vector<vector<int>> vec2d;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

vector<int> primes;
bitset<10000010> p;
ll sz;

void sieve(ll m) {
  sz = m + 1;
  p.set();
  p[0] = p[1] = 0;

  for (ll i = 2; i <= sz; i++) {
    if (p[i]) {
      for (ll j = i * i; j <= sz; j += i) {
        p[j] = 0;
      }
      primes.push_back(i);
    }
  }
}

bool isPrime(ll x) {
  if (x <= sz) {
    return p[x];
  }
  for (int i = 0; i < (int)primes.size(); i++) {
    if (x % primes[i] == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve(sqrt(numeric_limits<int>::max()));

  int n;
  while (cin >> n && n != 0) {
    set<ii> s;
    for (auto&& i : primes) {
      if (i < n && isPrime(n - i)) {
        ii x = make_pair(min(i, n - i), max(i, n - i));
        if (s.count(x) == 0) {
          s.insert(x);
        }
      }
    }
    cout << (int)s.size() << endl;
  }

  return 0;
}
