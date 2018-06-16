// Problem #    : 124
// Created on   : 2018-06-16 06:21:03

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
typedef vector<ii> vii;
typedef long long ll;

// Problem specific, not related to algorithm
map<string, int> mmap;
vector<string> vars;
vector<string> topsorts;

// Problem specific output formatting helper function
void translateTS(vi &res) {
  string s = "";
  for_each(res.begin(), res.end(), [&](int x) { s += vars[x]; });
  topsorts.push_back(s);
}

// Adjacency list
vec2d g;
void f(vi &res, vii &vind) {
  bool done = true;

  for (int i = 0; i < (int)g.size(); i++) {
    // first is visited flag, second is indegree
    if (vind[i] == ii(0, 0)) {
      // set; reduce indegree of all neighbors by 1
      for (auto &j : g[i]) vind[j].second--;
      vind[i] = ii(1, 0);  // set visible
      res.push_back(i);

      // recurse, then backtrack
      f(res, vind);

      // reset; increase (restore) indegree of all neighbors by 1
      for (auto &j : g[i]) vind[j].second++;
      vind[i] = ii(0, 0);  // reset visible
      res.pop_back();

      // flag
      done = false;
    }
  }

  if (done) {
    translateTS(res);
  }
}

void allTS() {
  vii vind((int)g.size(), ii(0, 0));
  for (auto &i : g)
    for (auto &j : i) vind[j].second++;

  vi res;
  f(res, vind);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc = 1;
  string l;
  while (getline(cin, l)) {
    if (l == "") break;

    // problem formatting
    if (tc > 1) cout << endl;
    tc++;

    stringstream ss(l);
    string s;

    // init
    mmap.clear();
    vars.clear();

    while (ss >> s) {
      vars.push_back(s);
      mmap.insert(make_pair(s, (int)vars.size() - 1));
    }

    // size our adj list and ind
    g.resize((int)vars.size());
    for (auto &i : g) {
      i.reserve((int)vars.size());
    }

    // read edges u --> v
    getline(cin, l);
    ss.clear();
    ss.str(l);
    string a, b;
    while (ss >> a >> b) {
      int u = mmap[a], v = mmap[b];
      g[u].push_back(v);
    }

    // find and print all topological sorts
    allTS();

    // sort and print
    sort(topsorts.begin(), topsorts.end());
    for (auto &i : topsorts) {
      cout << i << endl;
    }
    topsorts.clear();

    // clear
    g.resize(0);
  }

  return 0;
}
