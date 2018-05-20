// Problem #    : 102
// Title        : Ecological Bin Packing
// Accepted     : No
// Date         : 20180519

// Note: ---- messy, start over

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
typedef pair<int, char> ii;

void print(vec2d &v) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << setw(4) << fixed << v[i][j] << " \n"[j == 2];
    }
  }
  cout << "----------------" << endl;
}

void printVec(vi &v) {
  for (int i = 0; i < (int)v.size(); i++) {
    cout << setw(4) << fixed << v[i] << " \n"[i == (int)v.size() - 1];
  }
  cout << "================" << endl;
}

int main() {

  // template
  string s;
  while (getline(cin, s) && s != "") {
    stringstream ss(s);
    vec2d a(3, vi(3, 0));
    vec2d b(3, vi(3, 0));
    vi col(3, 0);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        ss >> a[i][j];
        col[i] += a[j][i];
      }
    }

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        int ans = 0;
        // for (int k = 0; k < 3; k++) {
        //   if (j == k) {
        //     continue;
        //   }
        //   ans += a[i][k];
        // }

        for (int k = 0; k < 3; k++) {
          if (i == k) {
            continue;
          }
          ans += a[k][j];
        }

        b[i][j] = ans;
      }
    }

    char c[3] = {'B', 'G', 'C'};
    ii ans[3];
    vector<bool> taken(3, false);
    for (int i = 0; i < 3; i++) {
      // first not taken
      int k;
      for (int q = 0; q < 3; q++) {
        if (!taken[q]) {
          k = q;
          break;
        }
      }
      // set initial
      ans[i] = make_pair(b[i][k], c[k]);

      // find minimal
      for (int j = 0; j < 3; j++) {
        ii x = make_pair(b[i][j], c[j]);
        if (x < ans[i] && !taken[j]) {
          k = j;
          ans[i] = x;
        }
      }
      taken[k] = true;
    }

    for (int i = 0; i < 3; i++) {
      cout << "Bin " << i + 1 << ": " << ans[i].first << ", " << ans[i].second
           << endl;
    }
    cout << endl;

    print(a);
    printVec(col);
    print(b);
  }

  return 0;
}
