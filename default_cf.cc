#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define db(args...)                          \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    error(_it, args);                        \
  }
void error(istream_iterator<string> it) {}
template <typename T, typename... Args>
void error(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  error(++it, args...);
}

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}
