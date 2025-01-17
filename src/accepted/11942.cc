// Problem #    : 11942
// Created on   : 2018-06-03 01:30:10

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

// e.g. int varX = 376; what_is(varX); prints "varX is 376"
// e.g. what_is(varX * 2 + 1); prints "varX * 2 + 1 is 753"
#define what_is(x) cerr << #x << " is " << x << endl;

// e.g. rep(i, 1, 10) is 1, 2, ..., 8, 9 and rep(i, 10, 1) is 9, 8, ..., 2, 1
#define rep(i, begin, end)                            \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

typedef vector<vector<int>> vec2d;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
bool isPalidrome(string s) {
  return equal(s.begin(), next(s.begin(), s.size() / 2), s.rbegin());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cout << "Lumberjacks:\n";

  int n;
  cin >> n;
  while (n--) {
    vector<int> v;
    v.reserve(10);
    copy_n(istream_iterator<int>(cin), 10, back_inserter(v));
    if (is_sorted(v.begin(), v.end()) || is_sorted(v.rbegin(), v.rend())) {
      cout << "Ordered\n";
    } else {
      cout << "Unordered\n";
    }
  }

  return 0;
}
