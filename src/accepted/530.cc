// Problem #    : 530
// Created on   : 2018-06-10 14:33:28

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

ll C(int n, int k) {
  if (k == 0 || k == n) return 1;
  ll ans = 1;
  k = min(k, n - k);
  for (ll i = 1; i <= k; i++) {
    // ans = ans * (n - k + i) / i;
    ans *= (n - k + i) / i;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  while (cin >> n >> k && (n || k)) {
    cout << C(n, k) << endl;
  }

  return 0;
}
