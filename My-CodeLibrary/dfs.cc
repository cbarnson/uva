// Problem #    : dfs
// Created on   : 2018-07-21 14:31:39

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

ostream &operator<<(ostream &os, vi &v) {
  for (auto &i : v)
    os << i << " ";
  os << endl;
}

vvi g;

void dfsUtil(int s, vb &vis) {
  vis[s] = true;
  for (auto &v : g[s]) {
    if (!vis[v]) {
      dfsUtil(v, vis);
    }
  }
}

void dfs(int s) {
  vb vis((int)g.size(), false);
  dfsUtil(s, vis);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
