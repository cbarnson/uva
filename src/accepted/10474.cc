// Problem #    : 10474
// Created on   : 2018-05-30 22:01:21
// Title        : Where is the Marble?
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q, tc = 1;
  while (cin >> n >> q) {
    if (n == 0 && q == 0) {
      break;
    }

    cout << "CASE# " << tc++ << ":\n";

    vector<int> a;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.push_back(x);
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < q; i++) {
      int x;
      cin >> x;
      auto lb = lower_bound(a.begin(), a.end(), x);
      int j = lb - a.begin();
      if (lb != a.end() && a[j] == x) {
        cout << x << " found at " << j + 1 << "\n";
      } else {
        cout << x << " not found\n";
      }
    }
  }

  return 0;
}
