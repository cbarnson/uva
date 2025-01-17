// Problem #    : 977-A
// Title        : A. Wrong Subtraction
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
  int n, k;
  while (cin >> n >> k) {
    while (k--) {
      if (n % 10 == 0) {
        n /= 10;
      } else {
        n--;
      }
    }

    cout << n << endl;
  }

  return 0;
}
