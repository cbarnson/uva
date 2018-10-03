#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int x, hh, mm;
  cin >> x >> hh >> mm;

  int s = hh * 60 + mm;
  for (int y = 0;; y++) {
    int nxt = (s + 24 * 60 - x * y) % (24 * 60);
    if ((nxt % 60) % 10 == 7 || (nxt / 60) == 7 || (nxt / 60) == 17) {
      cout << y << endl;
      return 0;
    }
  }
}
