// Problem #    : 113
// Title        : Power of Cryptography
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

int main()
{
  double n, p;
  while (cin >> n >> p)
  {
    cout << setprecision(0) << fixed << exp(log(p) / n) << endl;
  }

  return 0;
}
