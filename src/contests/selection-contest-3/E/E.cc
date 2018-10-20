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

  vector<ii> A(n);
  FR(i, n) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    A[i] = ii(a + b + c + d, i + 1);
  }

  sort(begin(A), end(A), [](ii a, ii b) {
    return a.first > b.first || (a.first == b.first && a.second < b.second);
  });

  FR(i, n) {
    if (A[i].second == 1) {
      cout << i + 1 << endl;
      return 0;
    }
  }
}
