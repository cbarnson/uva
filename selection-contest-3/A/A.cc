#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vi A(2010, 0), B(2010, 0);
  int cnt = 0;
  FR(i, n) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;

    int s = x + y, d = x - y + 1000;
    if (A[s])
      cnt += A[s];
    if (B[d])
      cnt += B[d];
    A[s]++;
    B[d]++;
  }

  cout << cnt << endl;
}
