// Problem #    : 138
// Created on   : 2018-07-18 20:46:46

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

typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints
typedef vector<vii> vvii;  // 2d vector of pairs
typedef vector<bool> vb;   // 1d vector of bools
typedef long long ll;

// formula:
// For pair of integers a, b
// 2 * (n ^ 2) = (x ^ 2) + x, where n = min(a, b) and x = max(a, b)
//
// from the above,
// n = sqrt((pow(x, 2) + x) / 2)
//
int main() {
  // int arr[] = {6,       8,       35,      49,       204,      288,     1189,
  //              1681,    6930,    9800,    40391,    57121,    235416, 332928,
  //              1372105, 1940449, 7997214, 11309768, 46611179, 65918161};
  // for (int i = 0; i < 20; i += 2)
  //   printf("%10d%10d\n", arr[i], arr[i + 1]);
  // return 0;

  int tc = 10;
  long long x = 8;
  double h;

  while (tc) {
    h = sqrt((x * x + x) >> 1);

    if (int(h) == h) {
      printf("%10d%10lld\n", int(h), x);
      --tc;
    }

    ++x;
  }

  return 0;
}
