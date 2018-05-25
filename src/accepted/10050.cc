// Problem #    : 10050
// Created on   : 2018-05-24 21:10:07
// Title        : Hartals
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

  int t, n, p;
  bool na[3651];

  cin >> t;
  while (t--)
  {
    cin >> n >> p;
    fill(na, na + n + 1, false);

    for (int i = 0; i < p; i++)
    {
      int x;
      cin >> x;
      for (int j = x; j <= n; j += x)
        na[j] = true;
    }

    for (int i = 7; i <= n + 1; i += 7)
    {
      na[i - 1] = false;
      if (i <= n)
        na[i] = false;
    }

    cout << count(na + 1, na + n + 1, true) << endl;
  }

  return 0;
}
