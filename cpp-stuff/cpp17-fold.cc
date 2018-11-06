// Problem #    : cpp17-fold
// Created on   : 2018-11-05 20:05:36
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

template <typename... Args>
bool all(Args... args) {
  return (... && args);
}

template <typename... Args>
void printer(Args&&... args) {
  (std::cout << ... << args) << '\n';
}

template <typename T, typename... Args>
void push_back_vec(std::vector<T>& v, Args&&... args) {
  static_assert((std::is_constructible_v<T, Args&> && ...));
  (v.push_back(args), ...);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  bool b = all(true, true, true, false);
  // within all(), the unary left fold expands as
  //  return ((true && true) && true) && false;
  // b is false

  printer(1, 2, 3, "abc");

  std::vector<int> v;
  push_back_vec(v, 6, 2, 45, 12);
  push_back_vec(v, 1, 2, 9);
  for (int i : v) std::cout << i << ' ';
}
