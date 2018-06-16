// Problem #    : 10689
// Created on   : 2018-06-15 17:32:35

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

// last 1, 2, 3, 4 digits of fibonacci numbers repeat with
// period of 60, 300, 1500, 15000 respectively.  seed values don't matter
int p[] = {60, 300, 1500, 15000};
int mod[] = {10, 100, 1000, 10000};

// alloc enough space to store up to the largest period (+ extra for safety
// always)
int f[15002] = {0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll a, b, n, m;
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b >> n >> m;
    m--;

    // smallest period is less than largest possible seed values, so makes sense
    // to mod our seed values here
    f[0] = a % mod[m], f[1] = b % mod[m];

    // compute for the rest of our period, taking the last mod[m] digits only
    for (int i = 2; i < p[m]; i++) {
      f[i] = (f[i - 1] + f[i - 2]) % mod[m];
    }

    // mod our input n by the period[m] to get the last m digits
    int ans = f[n % p[m]];
    cout << ans << endl;
  }

  return 0;
}
