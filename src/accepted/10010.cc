// Problem #    : 10010
// Created on   : 2018-07-17 18:41:15

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

int di[] = {-1, -1, -1, 0, 1, 1, 1};
int dj[] = {-1, 0, 1, 1, 1, 0, -1, -1};

string w;
vector<string> g;
int n, m;

void init() { g.clear(); }

bool inBound(int i, int j) { return (i >= 0 && i < m && j >= 0 && j < n); }

bool isMatch(int i, int j, int d, int c, int len) {
  if (c == len)
    return true;

  if (!inBound(i, j))
    return false;

  if (g[i][j] == w[c]) {
    return isMatch(i + di[d], j + dj[d], d, c + 1, len);
  }
  return false;
}

void print(int i, int j) { cout << i + 1 << " " << j + 1 << endl; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc;
  cin >> tc >> ws;
  while (tc--) {

    init();
    cin >> m >> n >> ws;
    for (int i = 0; i < m; i++) {
      string s;
      cin >> s;
      transform(s.begin(), s.end(), s.begin(), ::tolower);
      g.push_back(s);
    }

    int k;
    cin >> k;
    while (k--) {
      cin >> w >> ws;
      transform(w.begin(), w.end(), w.begin(), ::tolower);
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          for (int d = 0; d < 8; d++) {
            int len = w.length();
            int c = 0;
            if (isMatch(i, j, d, c, len)) {
              print(i, j);
              goto next;
            }
          }
        }
      }
    next:;
    }
    if (tc)
      cout << endl;
  }

  return 0;
}
