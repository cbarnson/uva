// Problem #    : 10137
// Created on   : 2018-06-09 21:19:51

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
  double arr[1000];
  int b[1000];

  while (cin >> n && n != 0) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      // round appropriately, for a double to an int
      b[i] = (int)((double)(arr[i] * 100.0) + 0.5);
      sum += b[i];
    }

    int loAvg = sum / n;

    // important! If sum not evenly divisble by n, then hi averge needs
    // to be 1 more than loAvg.  Since loAvg is truncated by division
    // (as shown above), we want to preserve the remaining 1 cent (and
    // it will never be more than 1 cent), where sum is not evenly divisible
    // by n, on the hiAvg, and take the max(lo, hi) to catch this occurrence,
    // if and when it occurs
    int hiAvg = loAvg + ((sum % n) ? 1 : 0);
    int hi = 0, lo = 0;
    for (int i = 0; i < n; i++) {
      if (b[i] > hiAvg) {
        hi += b[i] - hiAvg;
      }
      if (b[i] < loAvg) {
        lo += loAvg - b[i];
      }
    }

    int ans = max(lo, hi);

    // output according to formatting, without converting to floating point
    cout << "$" << (ans / 100) << "." << setw(2) << setfill('0') << (ans % 100)
         << endl;
  }
  return 0;
}
