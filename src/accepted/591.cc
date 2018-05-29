// Problem #    : 591
// Created on   : 2018-05-28 18:15:56
// Title        : Box of Bricks
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

  int n, tc = 1;
  int a[51];
  while (cin >> n)
  {
    if (n == 0)
      break;

    int s = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      s += a[i];
    }

    int av = s / n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      ans += abs(a[i] - av);
    }

    cout << "Set #" << tc++
         << "\nThe minimum number of moves is " << ans / 2 << ".\n\n";
  }

  return 0;
}
