// Problem #    : 10161
// Created on   : 2018-07-16 21:15:11

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

void soln(int n) {

  int x = 0, y = 0;
  int k = sqrt(n);
  if (k > 1) {
    if (k & 1)
      y = k - 1;
    else
      x = k - 1;
  }

  n = n - (k * k);
  if (n > 0) {
    if (k & 1)
      y++;
    else
      x++;
    n--;
  }

  ii d[][2] = {{ii(0, 1), ii(-1, 0)}, {ii(1, 0), ii(0, -1)}};

  int da = min(n, k);
  int db = min(n - da, k);

  x += d[k & 1][0].first * da;
  y += d[k & 1][0].second * da;

  x += d[k & 1][1].first * db;
  y += d[k & 1][1].second * db;

  cout << x + 1 << " " << y + 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    soln(n);
  }

  return 0;
}
