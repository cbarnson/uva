// Problem #    : 11185
// Created on   : 2018-06-10 00:17:25

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

string to_ternary(int n) {
  string ans = "";
  if (n == 0) {
    return "0";
  }
  while (n > 0) {
    int v = n % 3;
    ans += (char)(v + '0');
    n /= 3;
  }
  return string(ans.rbegin(), ans.rend());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n) {
    if (n < 0) {
      break;
    }

    cout << to_ternary(n) << endl;
  }

  return 0;
}
