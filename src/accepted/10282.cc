// Problem #    : 10282
// Created on   : 2018-08-10 18:13:05

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string l = "";
  map<string, string> mp;
  while (getline(cin, l) && l != "") {
    stringstream ss(l);
    string k, v;
    ss >> k >> v;
    if (mp.find(v) == mp.end()) {
      mp.insert(make_pair(v, k));
    }
  }

  while (cin >> l) {
    if (mp.find(l) == mp.end()) {
      cout << "eh\n";
    } else {
      cout << mp[l] << "\n";
    }
  }

  return 0;
}
