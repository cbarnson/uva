#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#if __has_include("default_cf.h")
#include "default_cf.h"
#endif

#define DEBUG 0

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int n, m, k, r;

struct curve {
  int len, cur;
};

// for road i, length SA[i], curve with length CR[i].len CR[i].cur precedes it
int SA[300];
curve CR[300];

vvi dp(300, vi(300, -1));

// dist for ith curve, in lane j (0-based), for problem
// must convert to 1-based
int curve_dist(int i, int j) {
  int ans = CR[i].len + CR[i].cur * (j + 1);
  return ans;
}

// dist for ith straightaway, with k lane changes (assume ok)
int road_dist(int i, int l) {
  int ans = SA[i] + l * r;
  return ans;
}

// range of lane indices reachable from SA[i], current lane j
ii range(int i, int j) {
  return {max(0, j - (SA[i] / k)), min(m - 1, j + (SA[i] / k))};
}

// 'f(i, j)' is the minimum distance to travel the ith SA and be in j
int f(int i, int j) {
  if (i == 0) {
    if (j == 0) return SA[0];
    return (dp[i][j] = (j > range(0, 0).second ? -2 : SA[0] + j * r));
  }

  int &x = dp[i][j];
  if (x != -1) return x;

  // Note: -1 ==> not computed, -2 ==> computed, not reachable
  ii R = range(i, j);
  int best = -1;
  for (int lane = R.first; lane <= R.second; lane++) {
    int d = f(i - 1, lane), lane_changes = abs(lane - j);
    if (d < 0) continue;
    d += curve_dist(i, lane) + road_dist(i, lane_changes);
    best = best == -1 ? d : min(best, d);
  }
  return (x = (best == -1 ? -2 : best));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> k >> r;

  FR(i, n) cin >> SA[i];
  for (int i = 1; i < n; i++) cin >> CR[i].len >> CR[i].cur;
  cout << f(n - 1, 0) << endl;
}
