// Problem #  : 651A
// Created on : 2018-Nov-01 12:46:44
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int a, b, t = 0;
  cin >> a >> b;

  if (b > a) swap(a, b);
  while (a > 1 && b > 0) {
    a -= 2;
    b++;
    t++;
    if (b > a) swap(a, b);
  }
  cout << t << endl;
}
