// Problem #    : 10034
// Created on   : 2018-06-10 13:41:03

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
typedef pair<double, double> dd;
typedef long long ll;

void printPair(ii p) {
  cout << "(" << p.first << ", " << p.second << ")" << endl;
}

void printPair(pair<double, ii> p) {
  cout << "(" << p.first << ", " << p.second.first << ", " << p.second.second
       << ")" << endl;
}

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

  int t, n, tc = 1;
  cin >> t;
  while (t--) {
    if (tc > 1) {
      cout << endl;
    }
    tc++;
    cin >> n;

    // read in N lines of the form: x y
    vector<dd> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i].first >> v[i].second;
    }

    // edge list, organized so as to take advantage of built-in sort mechanisms
    vector<pair<double, ii>> el;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        double w = hypot(v[i].first - v[j].first, v[i].second - v[j].second);
        el.push_back(make_pair(w, ii(i, j)));
      }
    }

    // sort, setup for Kruskals
    sort(el.begin(), el.end());
    double cost = 0.0;
    UF uf(n);
    for (int i = 0; i < (int)el.size(); i++) {
      if (!uf.same(el[i].second.first, el[i].second.second)) {
        cost += el[i].first;
        uf.merge(el[i].second.first, el[i].second.second);
      }
    }

    // print solution; cost of MST
    cout << setprecision(2) << fixed << cost << endl;
  }

  return 0;
}
