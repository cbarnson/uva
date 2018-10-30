// Problem #    : 151a
// Created on   : 2018-10-30 09:38:13
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;

  // total init volume
  int vol = k * l;
  int slice = c * d;
  
  int cnt = 0;
  while (1) {
     if (!slice || p < np || vol < nl) break;
     cnt++;
     slice--;
     p -= np;
     vol -= nl;	
  }
  cout << cnt / n << endl;
  
}
