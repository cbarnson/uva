// Problem #  : 507B
// Created on : 2018-Nov-09 13:54:19
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
typedef ll T;
struct pt {
  T x, y;
  pt operator+(pt p) { return {x + p.x, y + p.y}; }
  pt operator-(pt p) { return {x - p.x, y - p.y}; }
  pt operator*(T d) { return {x * d, y * d}; }
  bool operator==(pt a) { return (a.x == x && a.y == y); }
  T sq(pt p) { return p.x * p.x + p.y * p.y; }
  T dist(pt p) { return ((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y)); }
};

ll r;
pt a, b;
bool f(ll s) {
  ll dist = a.dist(b);
  ll d = r * s * s;
  if (d >= dist) return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> r >> a.x >> a.y >> b.x >> b.y;

  r *= 2;
  r *= r;

  ll lo = 0, hi = 1;
  if (a == b) goto lab;

  while (!f(hi)) hi *= 2LL;
  while (hi - lo > 5) {
    ll mid = lo + (hi - lo) / 2;
    (f(mid) ? hi : lo) = mid;
  }
  while (!f(lo)) lo++;
lab:
  cout << lo << endl;
}
