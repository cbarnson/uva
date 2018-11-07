// Problem #    : crossz
// Created on   : 2018-11-06 18:13:58
#include <bits/stdc++.h>
using namespace std;
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
#define PR(a, n)         \
  {                      \
    cout << #a << " = "; \
    FR(i, n)             \
    cout << a[i] << ' '; \
    cout << endl;        \
  }
#define FF(i, begin, end)                             \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

// -------- DEBUGGING --------
#define error(args...)                       \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
  }

void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
// Usage:
// error(a, b, c);
// Output:
// a = ...
// b = ...
// -------- DEBUGGING --------

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

void printSet(vii &A) {
  cout << "{ ";
  FR(i, A.size()) {
    auto [x, y] = A[i];
    cout << (i ? ", " : "") << "(" << x << "," << y << ")";
  }
  cout << " }" << endl;
}

int main() {
  cout << "Z_? x Z_? : ";
  int n, m;
  cin >> n >> m;

  vii A;
  FR(i, n) {
    FR(j, m) { A.emplace_back(i, j); }
  }

  printSet(A);
}
