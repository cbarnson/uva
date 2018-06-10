// Problem #    : 624
// Created on   : 2018-06-09 23:48:14

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

  int n;
  while (cin >> n) {
    int t;
    cin >> t;
    vi v(t);
    for (int i = 0; i < t; i++) {
      cin >> v[i];
    }

    int best = -1;
    int best_sum = -1;
    for (int i = 0; i < (1 << t); i++) {
      int sum = 0;
      for (int j = 0; j < t; j++) {
        if (i & (1 << j)) {
          sum += v[j];
        }
        // optimization to prune early
        if (sum > n) {
          break;
        }
      }
      // skip conditional update (i.e. take best), because invalid
      if (sum > n) {
        continue;
      }
      if (sum > best_sum) {
        best_sum = sum;
        best = i;
      }
      // found best, no need to continue
      if (sum == n) {
        break;
      }
    }

    // get set bits
    for (int i = 0; i < t; i++) {
      if (best & (1 << i)) {
        cout << v[i] << " ";
      }
    }
    cout << "sum:" << best_sum << endl;
  }

  return 0;
}
