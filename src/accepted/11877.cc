// Problem #    : 11877
// Created on   : 2018-07-22 15:02:20

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

ostream &operator<<(ostream &os, vi &v) {
  for (auto &i : v)
    os << i << " ";
  os << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n) {
    if (n == 0) {
      break;
    }

    int s = 0;
    while (n >= 3) {
      n -= 2;
      s++;
    }
    cout << ((n == 2) ? s + 1 : s) << endl;
  }

  return 0;
}
