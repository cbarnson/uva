// Problem #    : 10110
// Created on   : 2018-05-26 18:05:06
// Title        : Light, more light
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

bitset<10000010> p;
vector<ll> v;

void sieve(ll m)
{
  ll sz = m + 1;
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
      v.push_back(i);
    }
  }
}

ll numDiv(ll n)
{
  ll i = 0, pf = v[i], ans = 1;
  while (pf * pf <= n)
  {
    ll power = 0;
    while (n % pf == 0)
    {
      n /= pf;
      power++;
    }
    ans *= (power + 1);

    // bound check required to pass judge input
    if (i + 1 < (int)v.size())
      pf = v[++i];
    else
      break;
  }
  if (n != 1)
    ans *= 2;
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll m = pow(2, 32) - 1;
  sieve(sqrt(m));

  unsigned int n;
  while (cin >> n && n > 0)
  {
    int ans = numDiv(n);
    if (ans & 1)
    {
      cout << "yes\n";
    }
    else
    {
      cout << "no\n";
    }
  }
  return 0;
}
