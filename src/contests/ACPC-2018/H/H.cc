#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

template <typename T>
pair<T, vi> hungarian(const vector<vector<T>> &A) {
  int n = A.size(), m = A[0].size();
  T inf = numeric_limits<T>::max() / 2;
  vi way(m + 1), p(m + 1), used(m + 1), ans(n);
  vector<T> u(n + 1), v(m + 1), minv(m + 1, 0);
  for (int i = 1; i <= n; i++) {
    int j0 = 0, j1 = 0;
    p[0] = i;
    minv.assign(m + 1, inf), used.assign(m + 1, 0);
    do {
      int i0 = p[j0];
      j1 = 0;
      T delta = inf;
      used[j0] = true;
      for (int j = 1; j <= m; j++) {
        if (!used[j]) {
          T cur = A[i0 - 1][j - 1] - u[i0] - v[j];
          if (cur < minv[j]) minv[j] = cur, way[j] = j0;
          if (minv[j] < delta) delta = minv[j], j1 = j;
        }
      }
      for (int j = 0; j <= m; j++) {
        if (used[j])
          u[p[j]] += delta, v[j] -= delta;
        else
          minv[j] -= delta;
      }
    } while (j0 = j1, p[j0]);
    do {
      j1 = way[j0];
      p[j0] = p[j1];
      j0 = j1;
    } while (j0);
  }
  for (int i = 1; i <= m; i++) {
    if (p[i] > 0) ans[p[i] - 1] = i - 1;
  }
  return {-v[0], ans};
}

void modifyGraph(vector<vi> &G, int lo) {
  int n = G.size(), m = G[0].size();
  FR (i, n)
    FR (j, m)
      if (G[i][j] < lo) G[i][j]++;
  // G[i][j]++;
}

int sumDiffs(const vector<vi> &G, vi &ass, const int mx) {
  int s = 0;
  int n = ass.size();
  FR (i, n) {
    int j = ass[i];
    s += mx - G[i][j];
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  vector<vi> G(N, vi(M, 0));
  FR (i, N)
    FR (j, M)
      cin >> G[i][j];

  auto H = G;
  int mi = -1;
  for (int k = 1; k <= 200; k++) {
    // compute matching on 'H', our working copy of G
    auto ans = hungarian<int>(H);
    int weight;
    vi assignment;
    tie(weight, assignment) = ans;
    // int weight = ans.first;

    cout << "weight: " << weight << endl;

    // vi assignment = ans.second;

    int n = assignment.size();
    int mx = -1;
    FR (i, n) {
      int j = assignment[i];
      cout << i << " --> " << j << ", w = " << G[i][j] << endl;
      // cout << "====== in H, w = " << H[i][j] << endl;
      // cout << i << " assigned to " << assignment[i] << endl;
      // H[i][j] = max(H[i][j], k);
      mx = max(mx, G[i][j]);
    }

    // H[i][j] = max(H[i][j], k);
    // preprocess
    // modifyGraph(H, mx);

    cout << "longest time spend by any : " << mx << endl;
    int s = sumDiffs(G, assignment, mx);
    cout << "T : " << s << endl;

    // modifyGraph(H, mx);

    mi = mi == -1 ? s : min(mi, s);
  }
  cout << mi << endl;
  // cout << "final answer: " << mi << endl;
}
