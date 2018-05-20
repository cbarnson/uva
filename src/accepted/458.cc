// Problem #    : 458
// Title        : The Decoder
// Accepted     : Yes
// Date         : 20180519

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

typedef vector<vector<int>> vec2d;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

  // template
  string s;
  while (getline(cin, s) && s != "") {
    string ans = s;
    for (int i = 0; i < s.length(); i++) {
      ans[i] = (char)(s[i] - 7);
    }
    cout << ans << endl;
  }

  return 0;
}
