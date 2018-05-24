// Problem #    : 369
// Created on   : 2018-05-23 19:49:46
// Title        : Combinations
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

ll n, k;

int main()
{
  while (cin >> n >> k)
  {
    if (n == 0 && k == 0)
      break;

    ll ans = 1;
    for (ll i = 1; i <= (n - k); i++)
    {
      ans *= (k + i);
      ans /= i;
    }

    cout << n << " things taken " << k << " at a time is " << ans << " exactly." << endl;
  }

  return 0;
}
