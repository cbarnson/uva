// Created on : 2018-Oct-31 16:14:09
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  int A[550] = {};
  FR (i, n)
    cin >> A[i];

  int x, s = 0;
  FR (i, n) {
    if (i) {
      if (A[i - 1] + A[i] < k) {
        x = k - (A[i - 1] + A[i]);
        s += x;
        A[i] += x;
      }
    }
  }
  cout << s << endl;
  FR (i, n)
    cout << (i ? " " : "") << A[i];
  cout << endl;
}
