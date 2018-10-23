// Problem #    : 448a
// Created on   : 2018-10-23 09:59:44
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vi A(3), B(3);
  for (auto &x : A) cin >> x;
  for (auto &x : B) cin >> x;
  int n;
  cin >> n;
  int a = accumulate(begin(A), end(A), 0);
  int b = accumulate(begin(B), end(B), 0);
  int m = (a + 5 - 1) / 5 + (b + 10 - 1) / 10;
  if (m > n)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
