// Problem #    : 977-E
// Title        : E. Cyclic Components
// Accepted     : No
// Date         : 20180519

// All messed up, need cleaner approach for the "cycle" finding part

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

int N, M;
vector<vector<int>> g;

int dfsUtil(int u, vector<bool> &vis)
{
  // mark visited
  vis[u] = true;
  int ans = 1;
  for (int i = 0; i < (int)g[u].size(); i++)
  {
    int v = g[u][i];
    if (!vis[v])
    {
      // floodfill
      ans += dfsUtil(v, vis);
    }
  }

  // return the size of the discovered connected component
  return ans;
}

int dfs(int s, vector<bool> &visGroup)
{
  if (visGroup[s])
  {
    return 0;
  }

  vector<bool> vis(N, false);
  int sz = dfsUtil(s, vis);

  // output --> return 1 if is a cycle, 0 otherwise
  int ans = 0;
  vector<int> v;
  for (int i = 0; i < N; i++)
  {
    if (vis[i])
    {
      visGroup[i] = true;
      v.push_back(i);
    }
  }

  if (v.size() > 2)
  {

    vector<bool> seen(N, false);

    // just tranverse around the edge,
    int src = v[0];
    seen[src] = true;
    int last = src;
    int c = g[src][1];

    while (!seen[c])
    {
      seen[c] = true;

      int next = -1;
      for (int i = 0; i < (int)g[c].size(); i++)
      {
        if (g[c][i] != last)
        {
          next = g[c][i];
          break;
        }
      }
      if (next == -1)
      {
        break;
      }

      last = c;
      c = next;
    }
    if (c == src)
    {
      cout << "group with src " << src + 1 << " is a cycle" << endl;
      ans = 1;
    }
  }

  return ans;
}

void addEdge(int u, int v)
{
  g[u].push_back(v);
  g[v].push_back(u);
}

void printEdges()
{
  for (int i = 0; i < (int)g.size(); i++)
  {
    cout << i + 1 << " : ";
    for (int j = 0; j < g[i].size(); j++)
    {
      cout << g[i][j] + 1 << " ";
    }
    cout << endl;
  }
  cout << "---------" << endl;
}

int main()
{
  while (cin >> N >> M)
  {
    g.resize(N);
    for (auto &i : g)
    {
      i.reserve(N);
    }

    // read in M edges
    for (int i = 0; i < M; i++)
    {
      int u, v;
      cin >> u >> v;
      addEdge(u - 1, v - 1);
    }

    // floodfill
    vector<bool> visGroup(N, false);
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
      ans += dfs(i, visGroup);
    }

    cout << ans << endl;

    // debug
    printEdges();
  }
  return 0;
}
