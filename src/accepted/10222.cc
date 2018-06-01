// Problem #    : 10222
// Created on   : 2018-05-31 23:09:40

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

string key = "qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  char c;
  while (cin.get(c)) {
    auto i = key.find(tolower(c));
    if (i != string::npos && i > 1) {
      cout << key[(int)i - 2];
    } else {
      cout << c;
    }
  }

  return 0;
}
