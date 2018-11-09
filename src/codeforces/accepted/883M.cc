// Problem #  : 883M
// Created on : 2018-Nov-09 11:17:47
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

struct pt {
  int x, y;
  pt operator-(pt b) { return pt{x - b.x, y - b.y}; }
  pt operator+(pt b) { return pt{x + b.x, y + b.y}; }
  bool operator==(pt b) { return x == b.x && y == b.y; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  pt s, d;
  cin >> s.x >> s.y >> d.x >> d.y;

  s = s + pt{102, 102};
  d = d + pt{102, 102};

  pt dd = d - s;
  pt t{d.x, d.y};

  if (dd.x < 0) t.x--;
  if (dd.x > 0) t.x++;
  if (dd.y < 0) t.y--;
  if (dd.y > 0) t.y++;

  vvi D(300, vi(300, -1));
  D[s.x][s.y] = 0;

  queue<pt> q;
  q.emplace(s);
  while (!q.empty()) {
    pt f = q.front();
    q.pop();

    if (f == t) break;

    pt dir[] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    FR(i, 4) {
      pt b = f + dir[i];
      if (b.x < 0 || b.y < 0 || b.x >= 205 || b.y >= 205 ||
          (b.x == d.x && b.y == d.y))
        continue;

      if (D[b.x][b.y] != -1) continue;
      D[b.x][b.y] = D[f.x][f.y] + 1;
      q.emplace(b);
    }
  }

  int ans = D[t.x][t.y];
  cout << ans * 2 << endl;
}