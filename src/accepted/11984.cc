// Problem #    : 11984
// Created on   : 2018-06-12 21:41:42

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

  double c, d;
  int t, tc = 1;
  cin >> t;
  while (t--) {
    cin >> c >> d;
    cout << "Case " << tc++ << ": ";
    double ans = (d / 1.8) + c;

    cout << setprecision(2) << fixed << ans << endl;
  }

  return 0;
}
