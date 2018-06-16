// Problem #    : 10407
// Created on   : 2018-06-15 22:42:56

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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  while (getline(cin, s)) {
    if (s == "0" || s == "") break;
    stringstream ss(s);
    vi v;
    int x;
    while (ss >> x) {
      if (x == 0) break;
      v.push_back(x);
    }
    if (x != 0) continue;
    adjacent_difference(v.begin(), v.end(), v.begin());
    auto ans = accumulate(next(v.begin(), 1), v.end(), v[1],
                          [](int x, int y) { return gcd(x, y); });
    cout << (ans < 0 ? ans *= -1 : ans) << endl;
  }

  return 0;
}
