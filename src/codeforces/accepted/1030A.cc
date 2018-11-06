// Problem #  : 1030A
// Created on : 2018-Nov-05 21:50:18
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
#define FF(i, begin, end)                             \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, x;
  cin >> n;

  FR(i, n) {
    if (cin >> x; x) {
      cout << "HARD" << endl;
      return 0;
    }
  }

  cout << "EASY" << endl;
}
