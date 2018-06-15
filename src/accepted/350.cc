// Problem #    : 350
// Created on   : 2018-06-15 01:03:47

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
typedef long long ll;

int z, i, m, l;

// uva 350 - sample function you would use with cycle finding
int f(int x) { return (z * x + i) % m; }

// floyd cycle finding - tortoise and hare
ii floyd(int x0) {
  int t = f(x0), h = f(f(x0));
  while (t != h) {
    t = f(t);
    h = f(f(h));
  }

  int mu = 0;
  h = x0;
  while (t != h) {
    t = f(t);
    h = f(h);
    mu++;
  }

  int lambda = 1;
  h = f(t);
  while (t != h) {
    h = f(h);
    lambda++;
  }

  // mu is beginning of cycle, lambda is cycle length
  return ii(mu, lambda);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc = 1;
  while (cin >> z >> i >> m >> l) {
    if (z == 0 && i == 0 && m == 0 && l == 0) break;
    cout << "Case " << tc++ << ": ";
    ii ans = floyd(l);
    cout << ans.second << endl;
  }

  return 0;
}
