// Problem #    : 10079
// Created on   : 2018-05-23 18:50:21
// Title        : Pizza cutting
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

ll partialSum(ll n)
{
  return (n * (n + 1)) / 2;
}

// Is the https://en.wikipedia.org/wiki/Lazy_caterer%27s_sequence
int main()
{
  ll n;
  while (cin >> n && n >= 0)
  {
    cout << partialSum(n) + 1 << endl;
  }

  return 0;
}
