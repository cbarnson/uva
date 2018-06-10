// Problem #    : 147
// Created on   : 2018-06-09 20:12:09

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

ll coin[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
ll dp[30001][11];

ll f(int x, int y) {
  if (x == 0 || y == 0) {
    return 1;
  }

  ll ans = 0;
  for (ll i = 0; i <= (x / coin[y]); i++) {
    ans += dp[x - coin[y] * i][y - 1];
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i <= 30001; i++) {
    for (int j = 0; j < 11; j++) {
      dp[i][j] = f(i, j);
    }
  }

  double x;
  while (cin >> x) {
    if (x <= 0.0) {
      break;
    }
    int amt = (int)((double)(x * 100.0) + 0.5);
    cout << setprecision(2) << fixed << setw(6) << x;
    cout << setw(17) << *max_element(dp[amt], dp[amt] + 11) << endl;
  }

  return 0;
}
