// Created on : 2018-Oct-31 15:45:09
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

  int A[24][60] = {};
  int mx = 0;
  FR (i, n) {
    int h, m;
    cin >> h >> m;
    mx = max(mx, ++A[h][m]);
  }
  cout << mx << endl;
}
