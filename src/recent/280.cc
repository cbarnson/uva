// Problem #    : 280
// Created on   : 2018-07-04 18:17:22

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

typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints
typedef vector<vii> vvii;  // 2d vector of pairs
typedef vector<bool> vb;   // 1d vector of bools
typedef long long ll;

ostream &operator<<(ostream &os, ii &p) {
  os << "(" << p.first << ", " << p.second << ")\n";
}

ostream &operator<<(ostream &os, vi &v) {
  for (auto &i : v)
    os << i << " ";
  os << endl;
}
ostream &operator<<(ostream &os, vector<char> &v) {
  for (auto &i : v)
    os << i << " ";
  os << endl;
}

vvi g;
int n;

void dfsUtil(int s, vector<bool> &vis) {
  vis[s] = true;
  for (int i = 0; i < (int)g[s].size(); i++) {
    int v = g[s][i];
    if (!vis[v]) {
      dfsUtil(v, vis);
    }
  }
}

vi dfs(int s) {
  vector<bool> vis(n, false);

  // dfsUtil(s, vis);
  for (int i = 0; i < (int)g[s].size(); i++) {
    int v = g[s][i];
    if (!vis[v]) {
      dfsUtil(v, vis);
    }
  }

  vi ans;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      ans.push_back(i);
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n) {
    if (!n)
      break;

    g.resize(n);
    for (auto &i : g) {
      i.reserve(n);
    }

    int u, v;
    while (cin >> u) {
      if (!u)
        break;

      u--;
      while (cin >> v) {
        if (!v)
          break;
        v--;
        g[u].push_back(v);
      }
    }

    int x;
    cin >> x;
    while (x--) {
      int src;
      cin >> src;
      vi ans = dfs(src);
      cout << (int)ans.size();
      for (auto &j : ans) {
        cout << " " << j + 1;
      }
      cout << endl;
    }

    // for (int i = 0; i < x; i++) {
    //   int y;
    //   cin >> y;
    //   y--;
    //   vi ans = dfs(y);

    //   cout << (int)ans.size() << " ";
    //   for (auto &j : ans) {
    //     cout << j + 1 << " ";
    //   }
    //   cout << endl;
    // }

    g.resize(0);
  }

  return 0;
}
