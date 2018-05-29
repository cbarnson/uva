// Problem #    : 11150
// Created on   : 2018-05-28 20:52:39
// Title        : Cola
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

int dp[205][205];
int n;

int f(int i, int j)
{
  if (i < 3 && j < (3 - i))
  {
    return dp[i][j];
  }

  if (dp[i][j] != -1)
  {
    return dp[i][j];
  }

  if (i > 0)
  {
    return i + f(0, i + j);
  }

  return f(j / 3, j % 3);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // pre-compute; init
  for (int i = 0; i < 205; i++)
  {
    memset(dp[i], -1, sizeof dp[i]);
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < (3 - i); j++)
    {
      if (i + j == 2)
        dp[i][j] = i + 1;
      else
        dp[i][j] = i;
    }
  }

  int N = 201;
  for (int k = 3; k < N; k++)
  {
    for (int i = 0; i <= k; i++)
    {
      int j = k - i;
      dp[i][j] = f(i, j);
    }
  }

  int n;
  while (cin >> n)
  {
    cout << dp[n][0] << endl;
  }

  return 0;
}
