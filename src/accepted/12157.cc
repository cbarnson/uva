// Problem #    : 12157
// Created on   : 2018-06-16 04:03:00

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

  int t, tc = 1;
  cin >> t;
  while (t--) {
    cout << "Case " << tc++ << ": ";
    int n;
    cin >> n;
    int a = 0, b = 0, ac = 10, am = 30, bc = 15, bm = 60;

    for (size_t i = 0; i < n; i++) {
      int x;
      cin >> x;
      x += 1;
      int y = x;
      while (x > am) {
        x -= am;
        a += ac;
      }
      a += ac;
      while (y > bm) {
        y -= bm;
        b += bc;
      }
      b += bc;
    }

    if (a < b)
      cout << "Mile " << a << endl;
    else if (b < a)
      cout << "Juice " << b << endl;
    else
      cout << "Mile Juice " << a << endl;
  }

  return 0;
}
