// Problem #    : a
// Created on   : 2018-09-08 10:29:13

#include <bits/stdc++.h>

#define ALL(c) (c).begin(), (c).end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())

using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;
  while (cin >> n >> x) {
     int l, r, tot = 0, c = 1;
     for (int i = 0; i < n; i++) {
	cin >> l >> r;
	int y = (l - c) % x;
	tot += y + (r + 1 - l);
	c = r + 1;
     }
     cout << tot << "\n";
  }

  return 0;
}
