// Problem #  : 721A
// Created on : 2018-Nov-03 09:32:16
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
#define FF(i, begin, end)                             \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  string s;
  vi a;

  cin >> n >> s;
  FR(i, n) {
    int j = i;
    while (i < n && s[i] == 'B') i++;
    if (int x = i - j; x > 0) a.emplace_back(x);
  }

  cout << a.size() << endl;
  FR(i, a.size()) { cout << a[i] << " \n"[i == a.size() - 1]; }
}
