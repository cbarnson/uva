// Problem #    : 352
// Created on   : 2018-07-17 22:29:38

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

vector<string> g;
int n;
char c1 = '1', c2 = '0';

bool inBound(int i, int j) {
  return (i >= 0 && i < g.size() && j >= 0 && j < g.size());
}

int di[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dj[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int ff(int i, int j) {
  if (!inBound(i, j) || g[i][j] != c1)
    return 0;

  int ans = 0;
  g[i][j] = c2;
  for (int d = 0; d < 8; d++) {
    ans += ff(i + di[d], j + dj[d]);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc = 1;
  while (cin >> n >> ws) {
    g.clear();
    string s;
    for (int i = 0; i < n; i++) {
      cin >> s;
      g.push_back(s);
    }

    cout << "Image number " << tc++ << " contains ";
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (g[i][j] == c1) {
          ff(i, j);
          cnt++;
        }
      }
    }
    cout << cnt << " war eagles.\n";
  }

  return 0;
}
