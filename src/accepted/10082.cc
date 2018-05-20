// Problem #    : 10082
// Title        : WERTYU
// Accepted     : Yes
// Date         : 20180520

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
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef long long ll;

string intended = "`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.";
string actual = "1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./";

char translate(char c) {
  size_t found = actual.find(c);
  if (found != string::npos) {
    return intended[(int)found];
  } else {
    return c;
  }
}

int main() {
  // template
  string line;
  while (getline(cin, line) && line != "") {
    stringstream ss(line);
    char c;
    while (ss.get(c)) {
      cout << translate(c);
    }
    cout << endl;
  }

  return 0;
}
