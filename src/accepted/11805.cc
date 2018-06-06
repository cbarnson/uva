// Problem #    : 11805
// Created on   : 2018-06-05 22:59:46

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

  int t, n, p, k, tc = 1;
  cin >> t;
  while (t--) {

     cin >> n >> k >> p;

     cout << "Case " << tc++ << ": " << (((k - 1) + p) % n) + 1 << endl;

  }

  return 0;
}
