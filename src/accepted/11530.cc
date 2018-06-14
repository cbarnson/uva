// Problem #    : 11530
// Created on   : 2018-06-13 21:31:05

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

string key = " abcdefghijklmnopqrstuvwxyz";
string val = "112312312312312312341231234";

int getVal(char c) {
  auto i = key.find(c);
  return (int)((val[(int)i]) - '0');
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, tc = 1;
  char c;
  cin >> t;
  cin.ignore();

  while (t--) {
    int sum = 0;

    while (cin.get(c) && c != '\n') {
      sum += getVal(c);
    }

    printf("Case #%d: %d\n", tc++, sum);
  }

  return 0;
}
