// Problem #    : graphcheck
// Created on   : 2018-06-18 03:26:10

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
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints
typedef vector<vii> vvii;  // 2d vector of pairs
typedef vector<bool> vb;   // 1d vector of bools
typedef long long ll;

ostream &operator<<(ostream &os, ii &p) {
  os << "(" << p.first << ", " << p.second << ")\n";
}

ostream &operator<<(ostream &os, vi &v) {
  for (auto &i : v)
    os << i << " ";
  os << endl;
}
ostream &operator<<(ostream &os, vector<char> &v) {
  for (auto &i : v)
    os << i << " ";
  os << endl;
}

#define UNVISITED 0
#define EXPLORED 1
#define VISITED 2

vvi g;
vi vis, parent;
void graphcheck(int u) {
  vis[u] = EXPLORED;
  for (auto &v : g[u]) {
    if (vis[v] == UNVISITED) {
      parent[v] = u;
      graphcheck(v);
    } else if (vis[v] == EXPLORED) {
      if (v == parent[u])
        printf("two ways (%d, %d) <--> (%d, %d)\n", u, v, v, u);
      else
        printf("back edge (%d, %d) (cycle)\n", u, v);
    } else if (vis[v] == VISITED) {
      printf("forward edge (%d, %d)\n", u, v);
    }
  }
  vis[u] = VISITED;
}

void dfs() {
  vis.clear();
  parent.clear();
  vis.assign((int)g.size(), UNVISITED);
  parent.assign((int)g.size(), 0);

  int numcmp = 0;

  for (int i = 0; i < (int)g.size(); i++) {
    if (vis[i] == UNVISITED)
      printf("component %d:\n", ++numcmp), graphcheck(i);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
