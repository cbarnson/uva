// Problem #    : 11764
// Created on   : 2018-05-23 21:33:06
// Title        : Jumping Mario
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

int t, n, tc = 1;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;
  while (t--)
  {
    int x, y, hi = 0, lo = 0;
    cin >> n >> x;
    for (int i = 1; i < n; i++)
    {
      cin >> y;
      if (y > x)
        hi++;
      else if (y < x)
        lo++;

      x = y;
    }

    printf("Case %d: %d %d\n", tc++, hi, lo);
  }

  return 0;
}
