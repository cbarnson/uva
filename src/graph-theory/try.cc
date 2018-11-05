// Problem #    : try
// Created on   : 2018-11-04 21:32:56
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

void err(istream_iterator<string> it) {
}
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

int main(int argc, char **argv) {
  if (argc < 3) {
    cerr << "Fail\n";
    return 1;
  }

  ifstream fin;
  fin.open(argv[1]);

  ofstream fout;
  fout.open(argv[2]);

  auto print = [&](string x) {
    cout << x << endl;
    fout << x << endl;
  };

  auto isNotQuestion = [&](string x) {
    return !(x == "" || x.find("#") == 0 || x.find("SOLN") == 0);
  };

  string s;
  while (getline(fin, s)) {
    if (s.find("SOLN") == 0) {
      continue;
    }

    if (s.find("##") == 0) {
      cout << s << endl;
      fout << s << endl;
      string ans = "";
      getline(cin, ans);
      fout << ans << endl;
      continue;
    }

    if (s == "" || s.find("#") == 0) {
      cout << s << endl;
      fout << s << endl;
      continue;
    }
  }
}
