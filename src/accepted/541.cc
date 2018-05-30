// Problem #    : 541
// Created on   : 2018-05-29 22:26:45
// Title        : Error Correction
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

  int n;

  while (cin >> n)
  {
    if (n == 0)
    {
      break;
    }
    int a[101][101] = {0};

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> a[i][j];
      }
    }

    vector<int> r, c;
    for (int i = 0; i < n; i++)
    {
      int x = count(a[i], a[i] + n, 1);
      if (x & 1)
      {
        r.push_back(i);
      }
      int y = 0;
      for (int j = 0; j < n; j++)
      {
        if (a[j][i] == 1)
        {
          y++;
        }
      }
      if (y & 1)
      {
        c.push_back(i);
      }
    }

    if ((int)r.size() == 1 && (int)c.size() == 1)
    {
      cout << "Change bit (" << r[0] + 1 << "," << c[0] + 1 << ")\n";
    }
    else if (r.empty() && c.empty())
    {
      cout << "OK\n";
    }
    else
    {
      cout << "Corrupt\n";
    }
  }

  return 0;
}
