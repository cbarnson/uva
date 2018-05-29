// Problem #    : 10305
// Created on   : 2018-05-28 19:44:35
// Title        : Ordering Tasks
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

vec2d g;
int n, m;

void topsortUtil(int s, vector<bool> &vis, stack<int> &stk)
{
  vis[s] = true;
  for (int i = 0; i < (int)g[s].size(); i++)
  {
    int v = g[s][i];
    if (!vis[v])
    {
      topsortUtil(v, vis, stk);
    }
  }

  stk.push(s);
}

void topsort()
{

  stack<int> stk;
  vector<bool> vis(n, false);

  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
      topsortUtil(i, vis, stk);
    }
  }

  while (!stk.empty())
  {
    cout << stk.top() + 1;
    stk.pop();
    if (!stk.empty())
      cout << " ";
  }
  cout << "\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n >> m)
  {
    if (n == 0 && m == 0)
      break;

    g.resize(n);
    for (auto &i : g)
    {
      i.reserve(n);
    }

    for (int i = 0; i < m; i++)
    {
      int u, v;
      cin >> u >> v;
      g[u - 1].push_back(v - 1);
    }

    topsort();
  }

  return 0;
}
