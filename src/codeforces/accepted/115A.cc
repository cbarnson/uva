// Problem #  : 115A
// Created on : 2018-Nov-01 13:08:28
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

vector<vi> G;
vi D;

void dfs(int s, int e) {
  D[s] = s == e ? 0 : D[e] + 1;
  for (auto& v : G[s]) {
    if (v == e) continue;
    dfs(v, s);
  }
}

void add_edge(int u, int v) { G[u].emplace_back(v); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  G.assign(n, vi());

  FR (i, n) {
    int v = i, u;  // u --> v
    cin >> u;
    if (u != -1) {
      u--;
      add_edge(u, v);
    }
  }

  D.assign(n, -1);
  FR (i, n) {
    if (D[i] == -1) {
      dfs(i, i);
    }
  }

  cout << *max_element(begin(D), end(D)) + 1 << endl;
}
