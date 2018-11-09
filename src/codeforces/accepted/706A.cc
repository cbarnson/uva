// Problem #  : 706A
// Created on : 2018-Nov-09 13:28:19
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#if __has_include("default_cf.h")
#include "default_cf.h"
#endif

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

// Basic point structure
typedef double T;
struct pt {
  T x, y;
  pt operator+(pt p) { return {x + p.x, y + p.y}; }
  pt operator-(pt p) { return {x - p.x, y - p.y}; }
  pt operator*(T d) { return {x * d, y * d}; }
  bool operator==(pt a) { return (a.x == x && a.y == y); }
  T sq(pt p) { return p.x * p.x + p.y * p.y; }
  T dist(pt p) { return ((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y)); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  pt a;
  cin >> a.x >> a.y;
  int n;
  cin >> n;

  vector<pt> B(n);
  vector<double> V(n);
  FR(i, n) { cin >> B[i].x >> B[i].y >> V[i]; }

  double mi;

  FR(i, n) {
    double t = a.dist(B[i]) / (V[i] * V[i]);
    mi = i == 0 ? t : min(mi, t);
  }

  cout << setprecision(10) << fixed << sqrt(mi) << endl;
}
