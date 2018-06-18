// Problem #    : 929
// Created on   : 2018-06-18 01:17:05

#include <algorithm>
#include <assert.h>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> ii; // pair of ints
typedef pair<int, ii> iii;
typedef vector<int> vi;   // 1d vector of ints
typedef vector<ii> vii;   // 1d vector of pairs
typedef vector<vi> vvi;   // 2d vector of ints
typedef vector<vii> vvii; // 2d vector of pairs
typedef vector<bool> vb;  // 1d vector of bools
typedef long long ll;

#define INF 0x3f3f3f3f

vvi g;
vvi dist;
int N, M;

bool inbound(int i, int j) {
  if (i >= 0 && i < N && j >= 0 && j < M)
    return true;
  return false;
}

int dd[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dijk() {

  vvi dist(N, vi(M, INF));
  // careful: set this to the actual weight of the (0, 0) cell, NOT 0
  dist[0][0] = g[0][0];
  priority_queue<iii, vector<iii>, greater<iii>> pq;

  // careful: actually set this to the dist[0][0] not 0 (see above)
  pq.push(iii(dist[0][0], ii(0, 0)));
  while (!pq.empty()) {
    auto t = pq.top();
    pq.pop();
    ii u = t.second;
    for (int k = 0; k < 4; k++) {
      ii v = ii(u.first + dd[k][0], u.second + dd[k][1]);
      if (inbound(v.first, v.second)) {
        int w = g[v.first][v.second];
        if (dist[v.first][v.second] > dist[u.first][u.second] + w) {
          dist[v.first][v.second] = dist[u.first][u.second] + w;
          pq.push(iii(dist[v.first][v.second], ii(v.first, v.second)));
        }
      }
    }
  }
  return dist[N - 1][M - 1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    cin >> N >> M;

    g.clear();
    g.assign(N, vector<int>(M, 0));

    int dd[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        int w;
        cin >> w;
        g[i][j] = w;
      }
    }

    cout << dijk() << endl;
  }

  return 0;
}
