// Problem #    : 750
// Title        : 8 Queens Chess Problem
// Accepted     : Yes
// Date         : 20180501

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

bool isGood(vi &v, ii s) {
  int row = s.first - 1;
  int col = s.second - 1;
  return v[col] == row;
}

bool isValid(const vi &v) {
  for (int i = 0; i < 8 - 1; i++) {
    for (int j = i + 1; j < 8; j++) {
      int ca = i, ra = v[i], cb = j, rb = v[j];
      if (abs(ca - cb) == abs(ra - rb)) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ii s;
    cin >> s.first >> s.second;

    vi v(8);
    iota(v.begin(), v.end(), 0);

    cout << "SOLN       COLUMN\n";
    // cout << " #      1 2 3 4 5 6 7 8\n\n";

    cout << setw(2) << "#";
    cout << string(6, ' ') << "1 2 3 4 5 6 7 8" << endl << endl;

    int c = 1;
    while (next_permutation(v.begin(), v.end())) {
      if (isGood(v, s) && isValid(v)) {
        cout << setw(2) << c++;
        cout << string(6, ' ');
        for (int i = 0; i < 8; i++) {
          cout << v[i] + 1 << " \n"[i == 7];
        }
      }
    }

    if (t) {
      cout << endl;
    }
  }

  return 0;
}
