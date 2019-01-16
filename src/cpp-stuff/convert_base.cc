// Problem #    : convert_base
// Created on   : 2018-11-01 22:50:06
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

// TODO: convert to python
// Date: 2019-01-15 17:43:50
vi convert_base(const vi &x, int a, int b) {
  unsigned long long base10 = 0;
  FR(i, x.size()) base10 += x[i] * pow(a, x.size() - i - 1);
  int N = ceil(log(base10 + 1) / log(b));
  vi bb;
  for (int i = 1; i <= N; i++)
    bb.emplace_back((int)(base10 / pow(b, N - i)) % b);
  return bb;
}

vi base_digits(int x, int b = 10) {
  vi bb;
  while (x != 0) bb.emplace_back(x % b), x /= b;
  reverse(begin(bb), end(bb));
  return bb;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  vi x{1, 2, 3};
  int a = 5;

  vi z = convert_base(x, a, 10);
  PR(z, z.size());

  vi y = convert_base(x, a, 3);
  PR(y, y.size());

  // vi y = base_digits(123, 5);
  // PR(y, y.size());
}
