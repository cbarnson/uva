// Problem #    : 12455
// Title        : Bars
// Accepted     : Yes
// Date         : 20180502

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

int main() {
  int t, n, p;
  cin >> t;
  while (t--) {
    cin >> n >> p;
    vector<int> in(p);
    for (int i = 0; i < p; i++) {
      cin >> in[i];
    }

    int sum = 0;
    for (int i = 0; i < (1 << p); i++) {
      sum = 0;
      for (int j = 0; j < p; j++) {
        if (i & (1 << j)) {
          sum += in[j];
        }
      }
      if (sum == n) {
        break;
      }
    }

    printf("%s\n", (sum == n) ? "YES" : "NO");
  }

  return 0;
}
