// Problem #    : 11854
// Created on   : 2018-05-27 15:52:30
// Title        : Egypt
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

  int a[3];
  while (cin >> a[0] >> a[1] >> a[2])
  {
    if (a[0] == 0)
      break;

    sort(a, a + 3);
    if (a[2] * a[2] == (a[0] * a[0] + a[1] * a[1]))
    {
      cout << "right\n";
    }
    else
    {
      cout << "wrong\n";
    }
  }

  return 0;
}
