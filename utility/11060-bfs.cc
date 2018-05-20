// Problem #    : 11060
// Title        : Beverages
// Accepted     : No
// Date         : 20180519

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

#define INF -1
using namespace std;

typedef vector<vector<int>> vec2d;
typedef vector<int> vi;
typedef pair<int, int> ii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

template <typename T>
void printInitList(initializer_list<T> l)
{
  for (const auto &i : l)
    cout << i << ' ';
  cout << endl;
}

// variadic function
// int sum() { return 0; }
// template<typename T, typename... Args>
// T sum(T a, Args... args) { return a + sum(args...); }

vector<vector<int>> g;

int main()
{
  int tc = 1, n, m;
  while (cin >> n >> m)
  {
    g.resize(n);
    for (auto &i : g)
    {
      i.reserve(n);
    }

    for (int i = 0; i < m; i++)
    {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
    }

    // represents distance from source
    vector<int> d(n, INF);

    // start from source = 0
    int s = 0;
    d[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
      // queue layer by layer
      int u = q.front();
      q.pop();

      // for each neighbor of u
      for (int j = 0; j < (int)g[u].size(); j++)
      {
        int v = g[u][j];

        // if v is unvisited and reachable...
        if (d[v] == INF)
        {
          // if != INF, this is equivalent to being 'seen'.  Notice how we do this step
          // at the same time as enqueuing the children
          d[v] = d[u] + 1;

          // enqueue for next iteration
          q.push(v);
        }
      }
    }
  }

  printf("Case %d: Dilbert should drink beverages in this order: ", tc++);

  // B1 B2 B3 ... BN.

  return 0;
}
