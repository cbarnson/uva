// Problem #    : 977-C
// Title        : C. Less or Equal
// Accepted     : Yes
// Date         : 20180519

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

const int M = 1000000000;

using namespace std;
typedef long long ll;

int main() {
  int n, k;
  while (cin >> n >> k) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());

    int ans;
    if (k == 0) {
      ans = (v[0] > 1) ? 1 : -1;
      cout << ans << endl;
    } else if (k == n) {
      ans = (v[k - 1] <= M) ? M : -1;
      cout << ans << endl;
    } else {
      ans = ((v[k] - v[k - 1]) > 0) ? v[k] - 1 : -1;
      cout << ans << endl;
    }
  }

  return 0;
}
