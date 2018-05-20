// Problem #    : 977-B
// Title        : B. Two-gram
// Accepted     : Yes
// Date         : 20180519

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

int main() {
  int n;
  string s;
  while (cin >> n >> s) {
    map<string, int> m;
    int max = 0;
    string max_s = "";
    for (int i = 0; i < n - 1; i++) {
      string x = string() + s[i] + s[i + 1];
      m[x] += 1;
      if (m[x] > max) {
        max = m[x];
        max_s = x;
      }
    }
    cout << max_s << endl;
  }

  return 0;
}
