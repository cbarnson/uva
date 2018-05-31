// Problem #    : 357
// Created on   : 2018-05-30 23:37:03
// Title        : Let Me Count The Ways
// Accepted     : Yes

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

int coin[] = {1, 5, 10, 25, 50};
ll dp[30001][5] = {0};

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

  for (int i = 0; i <= 30000; i++) {
    for (int j = 0; j < 5; j++) {
      dp[i][j] = f(i, j);
    }
  }

  int n;
  while (cin >> n) {
    ll ans = dp[n][4];
    if (ans > 1) {
      cout << "There are " << ans << " ways to produce " << n
           << " cents change.\n";
    } else {
      cout << "There is only " << ans << " way to produce " << n
           << " cents change.\n";
    }
  }

  return 0;
}
