// Problem #  : 733A
// Created on : 2018-Nov-01 11:49:55
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  const string vowel = "AEIOUY";
  string s;
  cin >> s;
  s = "A" + s + "A";

  vi a;
  int n = s.size();
  FR (i, n)
    if (vowel.find(s[i]) != string::npos) a.emplace_back(i);

  int mx = -1;
  for (int i = 1; i < a.size(); i++) mx = max(mx, a[i] - a[i - 1]);

  cout << mx << endl;
}
