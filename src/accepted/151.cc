// Problem #    : 151
// Created on   : 2018-05-30 22:09:48
// Title        : Power Crisis
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

  int n;
  while (cin >> n && n != 0) {
    int m = 1;
    do {
      bitset<101> bs;
      bs.reset();

      // starting from 1
      int i = 1;

      // until 13 is marked
      while (!bs[13]) {
        // set bit
        bs[i] = 1;
        if (i == 13) {
          break;
        }

        // seek to next inactive bit, m times
        for (int j = 0; j < m; j++) {
          do {
            i = max(1, (i + 1) % (n + 1));
          } while (bs[i]);
        }
      }

      if ((int)bs.count() == n) {
        break;
      }

      m++;
    } while (1);

    cout << m << endl;
  }

  return 0;
}
