// Problem #    : 11461
// Created on   : 2018-05-26 19:29:34
// Title        : Square Numbers
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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> v;
  for (int i = 1; i <= sqrt(100000); i++)
  {
    v.push_back(i * i);
  }

  int a, b;
  while (cin >> a >> b)
  {
    if (a == 0 || b == 0)
    {
      break;
    }

    auto i = lower_bound(v.begin(), v.end(), min(a, b));
    auto j = upper_bound(v.begin(), v.end(), max(a, b));

    auto k = j - i;
    cout << k << endl;
  }

  return 0;
}
