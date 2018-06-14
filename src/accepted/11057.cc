// Problem #    : 11057
// Created on   : 2018-06-13 21:46:24

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

  int n, p;
  while (cin >> n)
  {
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      m[x] += 1;
    }
    cin >> p;

    for (int i = p / 2; i >= 0; i--)
    {
      if (m.count(i))
      {
        if (m.count(p - i))
        {
          if (i == (p - i) && m[i] < 2)
          {
            continue;
          }

          printf("Peter should buy books whose prices are %d and %d.\n\n", i,
                 p - i);
          break;
        }
      }
    }
  }

  return 0;
}
