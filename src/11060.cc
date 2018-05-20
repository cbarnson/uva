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

using namespace std;

typedef vector<vector<int>> vec2d;
typedef vector<int> vi;
typedef pair<int, int> ii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

template <typename T>
void printInitList(initializer_list<T> l) {
   for (const auto &i : l) cout << i << ' ';
   cout << endl;
}

// variadic function
// int sum() { return 0; }
// template<typename T, typename... Args>
// T sum(T a, Args... args) { return a + sum(args...); }

vector<vector<int>> g;
vector<int> ts;

const int UNVISITED = -1;
const int VISITED = 1;
int dfs_num[100];

void dfs(int s) {
   dfs_num[s] = VISITED;
   for (int i = 0; i < (int)g[s].size(); i++) {
      int v = g[s][i];
      if (dfs_num[v] == UNVISITED)
	 dfs(v);
   }
   ts.push_back(s);
}

int main() {

   int tc = 1, n, m;
   while (cin >> n >> m) {
      // init
      ts.clear();
      g.resize(n);
      for (auto &i : g) {
	 i.reserve(n);
      }

      memset(dfs_num, UNVISITED, sizeof dfs_num);

      // read
      for (int i = 0; i < m; i++) {
	 int u, v; cin >> u >> v;
	 g[u].push_back(v);
      }

      // process
      for (int i = 0; i < n; i++) {
	 if (dfs_num[i] == UNVISITED)
	    dfs(i);
      }

      // output
      for (int i = (int)ts.size() - 1; i >= 0; i--) {
	 printf(" %d", ts[i]);
      }
      cout << endl;

      

      



   }

   



   printf("Case %d: Dilbert should drink beverages in this order: ", tc++);

   // B1 B2 B3 ... BN.
   
   return 0;
}
