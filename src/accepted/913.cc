// Problem #    : 913
// Created on   : 2018-06-10 00:48:22

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

  ll n;
  while (cin >> n) {
    ll sum = 0;
    ll l = n / 2 + 1;
    ll x = (l * l) * 2 - 1;
    sum = x + (x - 2) + (x - 4);
    cout << sum << endl;
  }

  return 0;
}
