// Problem #    : 108
// Created on   : 2018-05-27 16:27:22
// Title        : Maximum Sum
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

const int NN = 101;

int mat[NN][NN];
int dp[NN][NN];

int f(int a, int b, int m, int n)
{
  m -= 1;
  n -= 1;

  int ans = dp[a + m][b + n];

  if (a > 0)
    ans -= dp[a - 1][b + n];
  if (b > 0)
    ans -= dp[a + m][b - 1];
  if (a > 0 && b > 0)
    ans += dp[a - 1][b - 1];

  return ans;
}

void compute(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int ans = mat[i][j];
      if (j > 0)
        ans += dp[i][j - 1];
      if (i > 0)
        ans += dp[i - 1][j];
      if (i > 0 && j > 0)
        ans -= dp[i - 1][j - 1];

      dp[i][j] = ans;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n)
  {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> mat[i][j];

    // memoization
    compute(n);

    // find max sum using pre-computed DP table
    int maxx = -127 * 100 * 100;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        for (int a = 0; a < n; a++)
        {
          for (int b = 0; b < n; b++)
          {
            if (a + i > n || j + b > n)
              continue;
            maxx = max(maxx, f(a, b, i, j));
          }
        }
      }
    }

    cout << maxx << endl;
  }

  return 0;
}
