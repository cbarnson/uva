// Problem #    : 10812
// Created on   : 2018-05-24 23:32:56
// Title        : Beat the spread
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

  int n, s, d;
  cin >> n;
  while (n--)
  {
    cin >> s >> d;

    int x = s - d;
    if (x < 0 || x & 1)
    {
      cout << "impossible\n";
      continue;
    }
    cout << d + (x / 2) << " " << (x / 2) << endl;
  }

  return 0;
}
