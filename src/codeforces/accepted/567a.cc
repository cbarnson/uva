// Problem #    : 567a
// Created on   : 2018-10-29 14:09:19
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vi A(n);
  for (auto &x : A) cin >> x;

  FR(i, n) {
    int x = A[i];
    int mi =
        (i == 0 ? abs(A[i + 1] - x)
                : (i == n - 1 ? abs(A[i - 1] - x)
                              : min(abs(A[i - 1] - x), abs(A[i + 1] - x))));
    int mx = max(abs(A.front() - x), abs(A.back() - x));
    cout << mi << " " << mx << endl;
  }
}
