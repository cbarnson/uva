// Problem #    : 572
// Created on   : 2018-05-24 21:42:19
// Title        : Oil Deposits
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

int m, n;
char g[101][101];

int di[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dj[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int ff(int i, int j, char c1, char c2)
{
  if (i < 0 || j < 0 || i >= m || j >= n)
    return 0;

  if (g[i][j] != c1)
    return 0;

  int ans = 1;
  g[i][j] = c2;

  for (int k = 0; k < 8; k++)
    ans += ff(i + di[k], j + dj[k], c1, c2);
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> m && m != 0)
  {
    cin >> n;

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> g[i][j];

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (g[i][j] == '@')
        {
          ff(i, j, '@', '*');
          cnt++;
        }
      }
    }

    cout << cnt << endl;
  }

  return 0;
}
