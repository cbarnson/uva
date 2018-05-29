// Problem #    : 575
// Created on   : 2018-05-28 19:02:59
// Title        : Skew Binary
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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  while (cin >> s && s != "0") {
    int len = (int)s.length();
    ll ans = 0;
    for (int i = 0; i < len; i++) {
      int j = len - i - 1;
      ans += (int)(s[i] - '0') * (pow(2, j + 1) - 1);
    }

    cout << ans << "\n";
  }

  return 0;
}
