// Problem #    : simpson_integrating
// Created on   : 2018-11-01 22:25:23
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
#define PR(a, n)         \
  {                      \
    cout << #a << " = "; \
    FR(i, n)             \
    cout << a[i] << ' '; \
    cout << endl;        \
  }
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

// http://e-maxx.ru/algo/simpson_integrating
// Used to calculate the value of definite integral
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  double a, b;
  const int N = 1000 * 1000;
  double s = 0;
  double h = (b - a) / N;
  for (int i = 0; i <= N; ++i) {
    double x = a + h * i;
    s += f(x) * ((i == 0 || i == N) ? 1 : ((i & 1) == 0) ? 2 : 4);
  }
  s *= h / 3;
}
