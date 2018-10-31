// Problem #    : 514A
// Created on   : 2018-Oct-31 00:10:29
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
  FR(i, s.size()) {
    char c = s[i];
    if (!i && s.front() == '9') {
      cout << c;
      continue;
    }
    if (c >= '5' && c <= '9') c = (char)('0' + (9 - (int)(c - '0')));
    cout << c;
  }
  cout << endl;
}
