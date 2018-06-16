// Problem #    : 12503
// Created on   : 2018-06-16 04:29:04

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n, ans = 0, j;
    string s, buf;
    cin >> n;
    vi v(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> s;
      if (s == "SAME") cin >> buf >> j;
      v[i] = s == "LEFT" ? -1 : s == "RIGHT" ? 1 : v[j - 1];
    }

    auto sum = std::accumulate(std::begin(v), std::end(v), 0,
                               [](int total, int x) { return total + x; });
    cout << sum << endl;
  }

  return 0;
}
