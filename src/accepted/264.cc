// Problem #    : 264
// Created on   : 2018-05-31 23:32:40

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

typedef long long ll;
typedef vector<vector<ll>> vec2d;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

ll dx[] = {0, 1, 1, -1};
ll dy[] = {1, -1, 0, 1};

ii getLoc(ll n) {
  ll d = 0, hop = 1;
  ll i = 0, j = 0, k = 1;
  while (k < n) {
    if (d & 1) {
      if (k + hop <= n) {
        i = i + hop * dx[d];
        j = j + hop * dy[d];
        k = k + hop;
      } else if (k + hop > n) {
        i = i + ((hop) - ((k + hop) - n)) * dx[d];
        j = j + ((hop) - ((k + hop) - n)) * dy[d];
        return make_pair(i, j);
      }
      hop++;
    } else {
      i = i + dx[d];
      j = j + dy[d];
      k = k + 1;
    }

    d = (d + 1) % 4;
  }
  return make_pair(i, j);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  while (cin >> n) {
    ii ans = getLoc(n);
    cout << "TERM " << n << " IS " << ans.first + 1 << "/" << ans.second + 1
         << endl;
  }

  return 0;
}
