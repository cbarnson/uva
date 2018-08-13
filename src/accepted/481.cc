// Problem #    : 481
// Created on   : 2018-08-11 04:17:03

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

vi sasc_seq(vi &A) {
  int n = (int)A.size();
  vector<int> last(n + 1), pos(n + 1), pred(n);
  if (n == 0) {
    return vi();
  }

  int len = 1;
  last[1] = A[pos[1] = 0];

  for (int i = 1; i < n; i++) {
    // lower_bound for strictly ascending
    int j = lower_bound(last.begin() + 1, last.begin() + len + 1, A[i]) -
            last.begin();
    pred[i] = (j - 1 > 0) ? pos[j - 1] : -1;
    last[j] = A[pos[j] = i];
    len = max(len, j);
  }

  int start = pos[len];
  vi S(len);
  for (int i = len - 1; i >= 0; i--) {
    S[i] = A[start];
    start = pred[start];
  }

  return S;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vi A;
  int x;
  while (cin >> x) {
    A.push_back(x);
  }

  vi ans = sasc_seq(A);
  cout << ans.size() << "\n-\n";
  for (auto &i : ans) {
    cout << i << "\n";
  }

  return 0;
}
