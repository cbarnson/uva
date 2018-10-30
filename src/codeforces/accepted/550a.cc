// Problem #    : 550a
// Created on   : 2018-10-29 14:23:12
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  s = "XX" + s + "XX";

  string k[] = {"AB", "BA"};
  auto n = s.size();

  FR(l, 2) {
    string x = k[l], y = k[!l];
    auto i = s.find(x);
    if (i != string::npos) {
      string a = s.substr(i + 2, n - i + 2);
      auto j = a.find(y);
      if (j != string::npos) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}
