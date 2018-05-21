// Problem #    : 374
// Title        : Big Mod
// Accepted     : Yes
// Date         : 20180521

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

typedef long long ll;

// Modular Exponentiation
ll modexp(ll x, ll n, ll m)
{
  if (n == 0)
    return 1;
  if (n & 1)
    return ((x % m) * (modexp(x, n - 1, m))) % m;

  ll y = modexp(x, n / 2, m);
  return (y * y) % m;
}

int main()
{
  // template
  ll b, p, m;
  while (cin >> b >> p >> m)
  {
    cout << modexp(b, p, m) << endl;
  }

  return 0;
}
