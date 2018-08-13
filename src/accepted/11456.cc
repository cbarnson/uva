// Problem #    : 11456
// Created on   : 2018-08-12 17:55:28

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

int asc[2005], desc[2005], A[2005];
int n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    REP(i, n) { cin >> A[i]; }

    // DP N^2 to find and store length of longest ascending subsequence
    for (int i = n - 1; i >= 0; i--) {
      asc[i] = 1;
      for (int j = i + 1; j < n; j++) {
        // less than, for ascending subseq
        if (A[i] < A[j]) {
          asc[i] = max(asc[i], asc[j] + 1);
        }
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      desc[i] = 1;
      for (int j = i + 1; j < n; j++) {
        // greater than, for descending subseq
        if (A[i] > A[j]) {
          desc[i] = max(desc[i], desc[j] + 1);
        }
      }
    }

    int ans = 0;
    REP(i, n) { ans = max(ans, asc[i] + desc[i] - 1); }
    cout << ans << "\n";
  }

  return 0;
}
