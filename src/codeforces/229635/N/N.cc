#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

vi C(1005, 0);
vector<vi> g;
void dfs(int s, int e) {
  C[s] = 1;
  for (auto &v : g[s]) {
    if (v != e) dfs(v, s), C[s] += C[v];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  g.assign(n, vi());
  for (int i = 1; i < n; i++) {
    int v;
    cin >> v;
    v--;
    g[v].push_back(i);
  }

  dfs(0, 0);
  FR(i, n) {
    if (C[i] == 1) continue;
    int s = 0;
    for (auto &v : g[i]) {
      if (C[v] == 1) s++;
    }
    if (s < 3) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
