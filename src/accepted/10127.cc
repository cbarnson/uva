// Problem #    : 10127
// Created on   : 2018-05-31 21:11:05
// Title        : Ones
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

int f(int n) {
  int o = 1;
  int cnt = 1;

  while (o % n != 0) {
    o = (((o % n) * (10 % n)) % n) + 1;
    // above is equivalent to below, due to mod rules
    // o = (o * 10 + 1) % n;

    cnt++;
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n) {
    cout << f(n) << endl;
  }

  return 0;
}
