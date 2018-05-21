// Problem #    :
// Title        :
// Accepted     : No
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
typedef pair<int, int> ii;
typedef long long ll;

// Modular Exponentiation
int modexp(int x, int n, int m)
{
  if (n == 0)
    return 1;
  if (n & 1)
    return ((x % m) * (modexp(x, n - 1, m))) % m;

  int y = modexp(x, n / 2, m);
  return (y * y) % m;
}

int main()
{
  // template

  return 0;
}
