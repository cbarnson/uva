// Problem #    : 11902
// Title        : Dominator
// Accepted     : Yes (1.750s)
// Date         : 20180501

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
int n;
vector<vector<int>> adj;

void dfsUtil(int s, vector<bool> &vis, int skip) {
  vis[s] = true;
  if (skip == s) {
    return;
  }
  for (int i = 0; i < adj[s].size(); i++) {
    int v = adj[s][i];
    if (!vis[v]) {
      // printf("Calling dfs %d -> %d\n", s, v);
      dfsUtil(v, vis, skip);
    }
  }
}

bool isreach(int y, int skip) {
  vector<bool> vis(n, false);
  dfsUtil(0, vis, skip);
  return vis[y];
}

int main() {
  int t, cn = 1;
  cin >> t;
  while (t--) {
    printf("Case %d:\n", cn++);

    cin >> n;

    adj.resize(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int x;
        cin >> x;
        if (x == 1) {
          adj[i].push_back(j);
        }
      }
    }

    vector<vector<char>> ans(n, vector<char>(n, 'Y'));

    // solve
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < n; y++) {
        if (!isreach(y, -1)) {
          ans[x][y] = 'N';
        } else if (isreach(y, x)) {
          ans[x][y] = 'N';
        } else {
          ans[x][y] = 'Y';
        }
      }
    }

    // every node dominates itself, as long as it is reachable from source
    for (int i = 0; i < n; i++) {
      if (isreach(i, -1)) {
        ans[i][i] = 'Y';
      }
    }

    // output
    string line = string(n * 2 + 1, '-');
    line[0] = line[line.length() - 1] = '+';
    cout << line << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << "|" << ans[i][j];
      }
      cout << "|" << endl;
      cout << line << endl;
    }

    adj.resize(0);
  }

  return 0;
}
