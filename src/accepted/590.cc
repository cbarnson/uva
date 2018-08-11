// Problem #    : 590
// Created on   : 2018-08-10 19:31:03

#include <bits/stdc++.h>

#define REP(v, n) for (int v = 0; v < (n); ++v)
#define FOR(v, c)                                                              \
  for (__typeof((c).begin()) v = (c).begin(); v != (c).end(); ++v)
#define ALL(c) (c).begin(), (c).end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define SZ(x) ((int)((x).size()))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints

#define INF 0x3f3f3f3f

int V, k;

int DP[10][1000];
int period[10][10];
int cost[10][10][30];

int getCost(int u, int v, int day) { return cost[u][v][day % period[u][v]]; }
int getDay(int dl) { return k - dl; }

// F(u, dl) represents the best cost, from 'u', with 'dl' days left (initially
// starting from k) to reach destination 'V'-1 with 0 days left.  As per problem
// statement 590, we will be interested in F(0, k) to get our solution.  Since
// 'dl' is a diminishing value with each call, we can consider our "exploration"
// of the graph to be acyclic.  Modelling the problem as a DAG allows the usage
// of DP bottom-up technique, greatly simplifying this problem.
int F(int u, int dl) {
  if (dl == 0) {
    if (u == V - 1)
      return (DP[u][dl] = 0);
    return (DP[u][dl] = INF);
  }

  // return from memory
  if (DP[u][dl] != -1)
    return DP[u][dl];

  int ans = INF;
  for (int v = 0; v < V; v++) {
    if (u != v) {
      int fromV = F(v, dl - 1);
      if (getCost(u, v, getDay(dl)) + fromV < ans) {
        ans = getCost(u, v, getDay(dl)) + fromV;
      }
    }
  }
  return (DP[u][dl] = ans);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc = 1;
  while (cin >> V >> k && (V || k)) {

    memset(DP, -1, sizeof DP);
    memset(period, -1, sizeof period);
    memset(cost, INF, sizeof cost);

    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (i != j) {
          cin >> period[i][j];
          for (int l = 0; l < period[i][j]; l++) {
            cin >> cost[i][j][l];
            if (cost[i][j][l] == 0)
              cost[i][j][l] = INF;
          }
        }
      }
    }
    cout << "Scenario #" << tc++ << "\n";
    int ans = F(0, k);
    if (ans == INF)
      cout << "No flight possible.\n\n";
    else
      cout << "The best flight costs " << ans << ".\n\n";
  }

  return 0;
}
