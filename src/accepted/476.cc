// Problem #    : 476
// Created on   : 2018-07-16 20:34:00

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

#define sz(a) (int)a.size()

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

struct pt {
  double x, y;
  pt(double xx, double yy) : x(xx), y(yy) {}
};

vector<pair<pt, pt>> v;

bool isIn(pt a, int i) {
  if (a.x > v[i].first.x && a.x < v[i].second.x && a.y < v[i].first.y &&
      a.y > v[i].second.y) {
    return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  char c;
  while (cin >> c) {
    if (c == '*')
      break;
    double a[4];
    for (int i = 0; i < 4; i++)
      cin >> a[i];
    v.push_back(make_pair(pt(min(a[0], a[2]), max(a[1], a[3])),
                          pt(max(a[0], a[2]), min(a[1], a[3]))));
  }

  double x, y;
  int cnt = 1;
  while (cin >> x >> y) {
    if (x == 9999.9 && y == 9999.9)
      break;

    bool found = false;
    for (int i = 0; i < v.size(); i++) {
      if (isIn(pt(x, y), i)) {
        cout << "Point " << cnt << " is contained in figure " << i + 1 << endl;
        found = true;
      }
    }

    if (!found) {
      cout << "Point " << cnt << " is not contained in any figure" << endl;
    }

    cnt++;
  }

  return 0;
}
