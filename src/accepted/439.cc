// Problem #    : 439
// Created on   : 2018-06-02 19:18:54

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef vector<vector<int>> vec2d;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

#define INF -1

const int NN = 8;

int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int toID(ii p) {
  return (p.first * NN) + p.second;
}

int toID(int i, int j) {
  return (i * NN) + j;
}

ii toXY(int id) {
  return make_pair(id / NN, id % NN);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  char a, b, x, y;
  while (cin >> a >> b >> x >> y) {
    int c, d, u, v;
    c = (int)(a - 'a');
    d = (int)(b - '1');
    u = (int)(x - 'a');
    v = (int)(y - '1');

    int s = toID(c, d);
    int dest = toID(u, v);

    int D[8 * 8 + 8 + 1];
    fill(D, D + (toID(NN, NN) + 1), INF);

    D[s] = 0;

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
      int w = q.front();
      q.pop();
      if (w == dest) {
        printf("To get from %c%c to %c%c takes %d knight moves.\n", a, b, x, y,
               D[w]);
        break;
      }

      for (int k = 0; k < NN; k++) {
        ii p = toXY(w);
        int i = p.first;
        int j = p.second;

        int di = i + dx[k];
        int dj = j + dy[k];

        if (di < 0 || di >= NN || dj < 0 || dj >= NN) {
          continue;
        }

        int neigh = toID(di, dj);

        if (D[neigh] == INF) {
          D[neigh] = D[w] + 1;
          q.push(neigh);
        }
      }
    }
  }

  return 0;
}
