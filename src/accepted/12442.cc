// Problem #    : 12442
// Created on   : 2018-06-17 18:40:23

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

#define MM 50005

int f[MM], dp[MM], vis[MM];
int n, t, tc = 1;

int dfs(int u) {
  int v = f[u];
  int a = 0;
  vis[u] = 1;
  if (vis[v] == 0) a = dfs(v) + 1;
  vis[u] = 0;
  dp[u] = a;
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      int u, v;
      cin >> u >> v;
      f[u] = v;
      dp[u] = -1;
      vis[u] = 0;
    }

    int ai = -1, a = -1;
    for (int i = 1; i <= n; i++) {
      if (dp[i] == -1) dfs(i);
      if (dp[i] > a) {
        a = dp[i];
        ai = i;
      }
    }
    printf("Case %d: %d\n", tc++, ai);
  }

  return 0;
}
