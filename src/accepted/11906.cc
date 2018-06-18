// Problem #    : 11906
// Created on   : 2018-06-17 14:36:34

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
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

void transpose(vec2d &A, vec2d &B) {
  int i, j, N = (int)A.size();
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) B[i][j] = A[j][i];
}

void print(vec2d &A) {
  for (auto &i : A) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void print(ii p) {
  cout << "(" << setw(2) << p.first << ", " << setw(2) << p.second << ")";
}

vec2d W;
vec2d A;
int RR, CC, NN, MM;
bool inbound(int i, int j) {
  return !(i < 0 || j < 0 || i >= RR || j >= CC || W[i][j] == 1);
}
vii childs(int x, int y, int n, int m) {
  vii ans;
  if (W[x][y] == 1) return ans;
  for (int i = 0; i < 2; i++) {
    if (i == 1 && n == m) continue;
    if (i == 1) swap(n, m);
    for (int j = 0; j < 4; j++) {
      if ((n == 0 || m == 0) && (j == 0 || j == 3)) continue;
      int fx = (j & 1) ? 1 : -1;
      int fy = (j & 2) ? 1 : -1;
      ii delta(fx * n, fy * m);

      int nx = delta.first + x, ny = delta.second + y;
      if (inbound(nx, ny)) {
        A[x][y]++;
        ans.push_back(ii(nx, ny));
      }
    }
  }
  return ans;
}
void dfsUtil(int i, int j, vec2d &vis) {
  vis[i][j] = 1;

  vii ch = childs(i, j, NN, MM);
  int sz = (int)ch.size();
  A[i][j] = sz;
  for (int i = 0; i < (int)ch.size(); i++) {
    ii v = ch[i];
    if (vis[v.first][v.second] == 0) {
      dfsUtil(v.first, v.second, vis);
    }
  }
}

void dfs(int n, int m) {
  RR = (int)A.size(), CC = (int)A[0].size(), NN = n, MM = m;
  vec2d vis(RR, vector<int>(CC, 0));

  dfsUtil(0, 0, vis);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, tc = 1;
  cin >> t;
  while (t--) {
    int R, C, N, M, w;
    cin >> R >> C >> M >> N >> w;

    A.resize(0);
    A.resize(R, vector<int>(C, 0));

    W.resize(0);
    W.resize(R, vector<int>(C, 0));

    while (w--) {
      int i, j;
      cin >> i >> j;
      W[i][j] = 1;
    }

    dfs(N, M);

    int odd = 0, evn = 0;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (i == 0 && j == 0 && A[i][j] == 0) {
          evn++;
          continue;
        }
        if (W[i][j] == 1 || A[i][j] == 0) continue;
        if (A[i][j] & 1)
          odd++;
        else
          evn++;
      }
    }

    cout << "Case " << tc++ << ": " << evn << " " << odd << endl;
  }

  return 0;
}

// determine the modifying values for the coordinates (i, j), taking only unique
// even when one of n or m equals 0, or n == m
// function assumes you won't call it with n == 0 && m == 0 (no change in any
// case there).
//
// Purpose:
// For moving like a (chess) knight, this function determines the unique moves
// (not considering boundaries) given move distance of N vertical and M
// horizontal, or N horizontal and M vertical.
//
// Alternatively:
// Just define arrays for the 1/-1 factors (i.e. dx[], dy[] arrays) and access
// values using loop indexes
void mark(int x, int y, int n, int m) {
  cout << "[ n = " << n << ", m = " << m << " ]" << endl;
  for (int i = 0; i < 2; i++) {
    // if n == m, then output of each outer loop would be identical, so only
    // loop once
    if (i == 1 && n == m) continue;

    // moving in a grid like a "knight", swap n and m
    if (i == 1) swap(n, m);
    for (int j = 0; j < 4; j++) {
      // if one of n or m is 0, skipping the outer cases of this inner loop
      // exclude those which would not be unique
      if ((n == 0 || m == 0) && (j == 0 || j == 3)) continue;
      int fx = (j & 1) ? 1 : -1;
      int fy = (j & 2) ? 1 : -1;
      ii delta(fx * n, fy * m);
      print(delta);
    }
    cout << endl;
  }
  cout << "=====" << endl;
}

// equivalent to above
void mark2(int n, int m) {
  cout << "[ n = " << n << ", m = " << m << " ]" << endl;
  ii nm[] = {ii(n, m), ii(m, n)};
  ii d[] = {ii(-1, -1), ii(-1, 1), ii(1, -1), ii(1, 1)};
  for (int i = 0; i < 2; i++) {
    if (n == m && i == 1) continue;
    for (int j = 0; j < 4; j++) {
      if ((n == 0 || m == 0) && (j == 0 || j == 3)) continue;
      ii delta(nm[i].first * d[j].first, nm[i].second * d[j].second);
      print(delta);
    }
    cout << endl;
  }
  cout << "=====" << endl;
}