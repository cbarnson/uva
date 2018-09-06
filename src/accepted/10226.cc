// Problem #    : 10226
// Created on   : 2018-09-05 19:38:44

#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, c)                                                              \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define SZ(x) ((int)((x).size()))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints
typedef vector<vii> vvii;  // 2d vector of pairs

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
     cin >> ws;
     multiset<string> ms;
     string s;
     while (getline(cin, s) && s != "") {
	ms.insert(s);
     }

     int tot = ms.size();
     auto i = ms.begin();
     while (i != ms.end()) {
	auto j = ms.upper_bound(*i);
	int s = distance(i, j);
	cout << *i << " ";
	double p = (double)100.0 * ((double)s / (double)tot);
	cout << setprecision(4) << fixed << p << "\n";
	i = j;
     }
     if (t) cout << "\n";
  }
  return 0;
}
