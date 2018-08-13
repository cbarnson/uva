// Problem #    : 11790
// Created on   : 2018-08-12 18:25:18

#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, c)                                                              \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define SZ(x) ((int)((x).size()))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints
typedef vector<vii> vvii;  // 2d vector of pairs

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    cin >> n;
    vi H(n), W(n);
    REP(i, n) { cin >> H[i]; }
    REP(i, n) { cin >> W[i]; }

    vii asc(n), desc(n);
    for (int i = n - 1; i >= 0; i--) {
      asc[i] = ii(W[i], 1);
      for (int j = i + 1; j < n; j++) {
        if (H[i] < H[j]) {
          if (asc[i].first < W[i] + asc[j].first) {
            asc[i].first = W[i] + asc[j].first;
            asc[i].second = asc[j].second + 1;
          }
        }
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      desc[i] = ii(W[i], 1);
      for (int j = i + 1; j < n; j++) {
        if (H[i] > H[j]) {
          if (desc[i].first < W[i] + desc[j].first) {
            desc[i].first = W[i] + desc[j].first;
            desc[i].second = desc[j].second + 1;
          }
        }
      }
    }

    ii ma = *max_element(asc.begin(), asc.end());
    ii md = *max_element(desc.begin(), desc.end());
    cout << "Case " << tc << ". ";
    if (ma.first < md.first) {
      cout << "Decreasing (" << md.first << "). Increasing (" << ma.first
           << ").\n";
    } else {
      cout << "Increasing (" << ma.first << "). Decreasing (" << md.first
           << ").\n";
    }
  }

  return 0;
}
