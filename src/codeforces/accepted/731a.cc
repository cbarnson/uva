// Problem #    : 731a
// Created on   : 2018-10-29 14:53:04
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int n;
int f(int i) { return (i + 1) % n; }
int r(int i) { return (i + n - 1) % n; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string a = "abcdefghijklmnopqrstuvwxyz";

  string s;
  cin >> s;

  char c = 'a';
  int ans = 0;
  FR(i, s.size()) {
    int k = a.find(c), j = a.find(s[i]);
    int x = abs(j - k);
    int y = 26 - x;
    ans += min(x, y);
    c = s[i];
  }
  cout << ans << endl;
}
