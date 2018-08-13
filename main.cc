// Problem #    : main
// Created on   : 2018-08-06 16:41:58

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

// union find implementation
class UF {
  // vi p : p[i] stores the index of parent item (i.e. the immediate parent of
  //        item i), if p[i] = i, item i is the representative item of a certain
  //        disjoint set.
  // vi r : r[i] is the UPPER BOUND of the height of the tree rooted at i
  vi p, r;

public:
  UF(int n) {
    p.assign(n, 0);
    iota(p.begin(), p.end(), 0);
    r.assign(n, 0);
  }

  int find(int i) { return (p[i] == i) ? i : (p[i] = find(p[i])); }

  bool same(int i, int j) { return find(i) == find(j); }

  void merge(int i, int j) {
    if (!same(i, j)) {
      int x = find(i), y = find(j);
      if (r[x] > r[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (r[x] == r[y]) {
          r[y]++;
        }
      }
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
