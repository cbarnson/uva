#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int x, y;
  cin >> y >> x;

  if (x == 0 || (x == 1 && y != 0) || (y < (x - 1))) {
    cout << "No" << endl;
    return 0;
  }

  cout << ((x % 2) == (y % 2) ? "No" : "Yes") << endl;
}
