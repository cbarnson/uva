// Problem #    : 119a
// Created on   : 2018-10-20 21:03:17
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, n;
  cin >> a >> b >> n;

  int f = 1;
  while (1) {
    int m = __gcd((f ? a : b), n);
    if (n < m) break;
    n -= m;
    f = !f;
  }

  cout << f << endl;
}
