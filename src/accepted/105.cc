// Problem #    : 105
// Created on   : 2018-06-14 20:51:03

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

int H[10002] = {0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int x, h, y;
  int max_y = 0;
  while (cin >> x >> h >> y) {
    max_y = max(max_y, y);
    for (int i = x; i < y; i++) {
      H[i] = max(H[i], h);
    }
  }

  int last = 0;
  for (int i = 0; i < max_y; i++) {
    if (H[i] != last) {
      cout << i << " " << H[i] << " ";
      last = H[i];
    }
  }
  cout << max_y << " " << 0 << endl;

  return 0;
}
