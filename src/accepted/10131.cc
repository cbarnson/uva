// Problem #    : 10131
// Created on   : 2018-07-18 21:26:19

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

#define INF -1
using namespace std;
struct node {
  int w, iq, id;
  int path;
  node *prev;
  node(int _w, int _iq, int _id) : w(_w), iq(_iq), id(_id), path(INF) {}
  bool operator<(const node &rhs) const { // sort decreasing order of weight
    return (w == rhs.w) ? (iq < rhs.iq) : (w > rhs.w);
  }
  bool operator()(node &rhs) { // connect
    if (w > rhs.w && iq < rhs.iq && path + 1 > rhs.path) {
      rhs.path = path + 1;
      rhs.prev = this;
    }
  }
};
void out(node *p) {
  cout << p->id << endl;
  if (p->path == 1)
    return;
  out(p->prev);
}
int main() {
  int a, b, c(0);
  vector<node> v;
  while (cin >> a >> b)
    v.push_back(node(a, b, ++c));
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    if (v[i].path == INF)
      v[i].path = 1; // 1 offset
    for (int j = i + 1; j < v.size(); j++)
      v[i](v[j]); // connect operator
  }
  node *p = &v[0];
  for (int i = v.size() - 1; i > 0; i--) {
    if (v[i].path > p->path)
      p = &v[i];
  }
  cout << p->path << endl;
  out(p);
}