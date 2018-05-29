// Problem #    : 10929
// Created on   : 2018-05-28 20:03:13
// Title        : You can say 11
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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string n;
  while (cin >> n && n != "0")
  {
    bool fg = false;
    int ans = 0;
    for (auto i = n.rbegin(); i != n.rend(); ++i)
    {
      if (i == n.rbegin())
      {
        ans = (int)(*i - '0');
        continue;
      }

      if (!fg)
      {
        ans -= (int)(*i - '0');
      }
      else
      {
        ans += (int)(*i - '0');
      }
      fg = !fg;
    }

    cout << n << " is ";
    if (ans % 11 != 0)
    {
      cout << "not ";
    }
    cout << "a multiple of 11.\n";
  }

  return 0;
}
