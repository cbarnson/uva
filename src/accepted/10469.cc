// Problem #    : 10469
// Created on   : 2018-05-28 19:29:56
// Title        : To Carry or not to Carry
// Accepted     : No

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
typedef unsigned long long ull;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  unsigned int x, y;
  while (cin >> x >> y)
  {
    cout << (x ^ y) << endl;
  }

  return 0;
}
