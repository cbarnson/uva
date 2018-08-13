
#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, c)                                                              \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define SZ(x) ((int)((x).size()))

// printf("%d", (({int x=1; REP(i,10) x*=i+1; x;})));

// finding the smallest i such that, for all j
// i % mods[j] == vals[j] could be done just by writing
// return FIRST(i, 0, INF, FORALL(j, 0, Size(vals), i % mods[j] == vals[j]))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
