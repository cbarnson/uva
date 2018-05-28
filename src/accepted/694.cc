// Problem #    : 694
// Created on   : 2018-05-27 15:41:28
// Title        : The Collatz Sequence
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

ll l;

ll f(ll n)
{
  if (n == 1)
    return 1;

  if (n > l)
    return 0;

  ll ans = 1;
  if (n & 1)
    return ans + f(3 * n + 1);

  return ans + f(n / 2);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc = 1;
  ll a;
  while (cin >> a >> l)
  {
    if (l < 1)
      break;

    printf("Case %d: A = %d, limit = %d, number of terms = %d\n", tc++, (int)a, (int)l, f(a));
  }

  return 0;
}
