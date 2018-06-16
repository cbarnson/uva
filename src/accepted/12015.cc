// Problem #    : 12015
// Created on   : 2018-06-16 02:44:17

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

typedef pair<int, pair<int, string>> iis;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // test comment
  int t, tc = 1;
  cin >> t;
  while (t--) {
    cout << "Case #" << tc++ << ":\n";
    string s;
    int r, hi = 0;
    vector<pair<int, string>> V;
    for (int i = 0; i < 10; i++) {
      cin >> s >> r;
      V.push_back(make_pair(r, s));
      hi = max(hi, r);
    }

    for (auto &i : V) {
      if (i.first == hi) {
        cout << i.second << endl;
      }
    }
  }

  return 0;
}
