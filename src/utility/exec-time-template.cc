// Problem #    : main
// Created on   : 2018-06-14 18:35:01
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <bitset>
#include <chrono>
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
using namespace std::chrono;

typedef vector<vector<int>> vec2d;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

vi primes;
bitset<10000010> p;
ll sz;

void sieve(ll m) {
  sz = m + 1;
  p.set();
  p[0] = p[1] = 0;
  for (ll i = 2; i <= sz; i++)
    if (p[i]) {
      for (ll j = i * i; j <= sz; j += i) p[j] = 0;
      primes.push_back(i);
    }
}

bool isPrime(ll x) {
  if (x <= sz) return p[x];
  for (int i = 0; i < (int)primes.size(); i++)
    if (x % primes[i] == 0) return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  auto t1 = high_resolution_clock::now();

  // put code under test here...
  sieve(10000000);
  cout << "Total primes:   " << primes.size() << endl;
  cout << "Largest prime:  " << primes.back() << endl;
  auto t2 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(t2 - t1);
  cout << "Execution time: " << duration.count() << " microseconds" << endl;

  return 0;
}
