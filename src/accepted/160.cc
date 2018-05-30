// Problem #    : 160
// Created on   : 2018-05-29 22:50:40
// Title        : Factors and Factorials
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

vector<ll> primes;
bitset<10000010> p;
ll sz;

void sieve(ll m)
{
  sz = m + 1;
  p.set();
  p[0] = p[1] = 0;
  for (ll i = 2; i <= sz; i++)
  {
    if (p[i])
    {
      for (ll j = i * i; j <= sz; j += i)
      {
        p[j] = 0;
      }
      primes.push_back(i);
    }
  }
}

bool isPrime(ll x)
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

vi primeFactors(ll n)
{
  vi ans;
  ll i = 0, pf = primes[i];
  while (pf * pf <= n)
  {
    while (n % pf == 0)
    {
      n /= pf;
      ans.push_back(pf);
    }
    pf = primes[++i];
  }
  if (n != 1)
  {
    ans.push_back(n);
  }

  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve(sqrt(numeric_limits<int>::max()));

  ll n;
  while (cin >> n)
  {
    if (n == 0)
    {
      break;
    }

    cout << setw(3) << n << "! =";

    map<int, int> m;
    int maxx = -1;
    for (ll i = n; i > 0; i--)
    {
      vi tmp = primeFactors(i);
      for (auto &j : tmp)
      {
        if (m.count(j) > 0)
        {
          m[j] += 1;
        }
        else
        {
          m.insert(make_pair(j, 1));
        }

        maxx = max(maxx, j);
      }
    }

    int k = 0;
    for (auto &i : primes)
    {
      if (i > maxx)
      {
        break;
      }

      if (k > 0 && k % 15 == 0)
      {
        cout << "\n      ";
      }
      cout << setw(3) << m[i];
      k++;
    }
    cout << "\n";
  }

  return 0;
}
