// Problem #    : 17_1
// Created on   : 2018-11-05 19:56:31
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

// C++17
template <typename... Args>
auto Func(Args... args) {
  return (args + ...);
}

// C++17
template <typename T, typename... Args>
void pushToVector(vector<T>& v, Args&&... args) {
  (v.push_back(forward<Args>(args)), ...);
  //  v.push_back(forward<Args_1>(arg1)),
  //  v.push_back(forward<Args_2>(arg2)),
  //  ....
}

// C++17
template <typename... Args>
void readln(Args&... args) {
  ((cin >> args), ...);
}

template <typename... Args>
void writeln(Args... args) {
  ((cout << args << " "), ...);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cout << Func(1, 2, 3, 4, 5);  // 15

  vector<int> v;
  pushToVector(v, 1, 4, 5, 8);

  int x;
  double y;
  readln(x, y);                  // enter 100 500.1234
  writeln(x, "some string", y);  // 100 some string 500.1234

  map<int, string> m;
  for (auto [key, value] : m)
    cout << "key: " << key << '\n' << "value: " << value << '\n';
}
