// Problem #    : 11679
// Created on   : 2018-06-16 02:26:03

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

  int b, n;
  while (cin >> b >> n) {
    if (b == 0 && n == 0) break;
    vi R(b + 1, 0);
    for (int i = 1; i <= b; i++) cin >> R[i];

    for (int i = 0; i < n; i++) {
      int d, c, v;
      cin >> d >> c >> v;
      R[d] -= v;
      R[c] += v;
    }

    auto ans = any_of(R.begin(), R.end(), [](int x) { return x < 0; });
    if (ans)
      cout << "N\n";
    else
      cout << "S\n";
  }

  return 0;
}
