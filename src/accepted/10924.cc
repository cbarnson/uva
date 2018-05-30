// Problem #    : 10924
// Created on   : 2018-05-29 22:04:27
// Title        : Prime words
// Accepted     : Yes

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

const int NN = 52 * 20;

bitset<10000010> p;
vector<int> primes;
ll sz;

ll sieve(ll m)
{
  sz = m + 1;
  p.set();
  p[0] = 0;
  for (ll i = 2; i <= sz; i++)
  {
    if (p[i])
    {
      for (ll j = i * i; j <= sz; j += i)
      {
        p[j] = 0;
      }
      primes.push_back((int)i);
    }
  }
}

bool isPrime(int x)
{
  if (x <= sz)
  {
    return p[x];
  }

  for (int i = 0; i < (int)primes.size(); i++)
  {
    if (x % primes[i] == 0)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll m = sqrt(numeric_limits<int>::max());
  sieve(m);

  string s;
  while (cin >> s)
  {

    ll ans = 0;
    for_each(s.begin(), s.end(), [&](char c) {
      if (c >= 'a' && c <= 'z')
      {
        ans += (int)(c - 'a') + 1;
      }
      else if (c >= 'A' && c <= 'Z')
      {
        ans += (int)(c - 'A') + 27;
      }
    });

    if (isPrime(ans))
    {
      cout << "It is a prime word.\n";
    }
    else
    {
      cout << "It is not a prime word.\n";
    }
  }

  return 0;
}
