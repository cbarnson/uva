// Problem #    : 11060
// Title        : Beverages
// Accepted     : Yes
// Date         : 20180519
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <utility>
#include <vector>

using namespace std;

// typedef pair<int, int> ii;

int main() {
  int tc = 1, n, m;

  while (cin >> n) {

    // if (tc > 1) {
    //   cout << endl << endl;
    // }

    // read items
    map<string, int> mp;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      words[i] = s;
      mp[s] = i;
    }

    vector<vector<int>> g(n);
    vector<int> deg(n, 0);

    // read
    cin >> m;
    for (int i = 0; i < m; i++) {
      string su, sv;
      cin >> su >> sv;
      g[mp[su]].push_back(mp[sv]);
      deg[mp[sv]]++;
    }

    // enqueue vertices with 0 indegree
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) {
        // cout << "pushing " << i << endl;
        q.push(i);
      }
    }

    // stores our toposort
    vector<int> ts;

    while (!q.empty()) {

      int u = q.top();
      // cout << "queue top: " << u << endl;
      q.pop();
      ts.push_back(u);

      // remove u and all outgoing edges from u
      for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];

        // decrease the in-degree of each child
        // if such removal causes v to have 0 in-degree, enqueue
        if (deg[v] - 1 == 0) {
          q.push(v);
        }
        deg[v]--;
      }
    }

    cout << "Case #" << tc++
         << ": Dilbert should drink beverages in this order:";
    for (int i = 0; i < (int)ts.size(); i++) {
      cout << " " << words[ts[i]];
    }
    cout << "." << endl << endl;
  }

  return 0;
}
