// Problem #    : 10432
// Created on   : 2018-07-21 21:35:23

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

const double PI = acos(-1.0);

double csq(double a, double b, double C) {
  return a * a + b * b + 2 * a * b * cos(C);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  double r;
  int n;
  while (cin >> r >> n) {

    double h = r * cos(PI / (double)n);
    double b = r * sin(PI / (double)n);
    double ans = h * b * n;
    cout << setprecision(3) << fixed << ans << endl;
  }

  return 0;
}
