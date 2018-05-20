// Problem #    : 10783
// Title        : Odd Sum
// Accepted     : Yes
// Date         : 20180519

#include <algorithm>
#include <assert.h>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <utility>
#include <vector>

using namespace std;

typedef vector<vector<int>> vec2d;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

  // template
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int j = min(a, b); j <= max(a, b); j++) {
      if (j & 1) {
        ans += j;
      }
    }
    cout << "Case " << i << ": " << ans << endl;
  }

  return 0;
}
