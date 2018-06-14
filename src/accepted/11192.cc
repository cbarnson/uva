// Problem #    : 11192
// Created on   : 2018-06-14 01:34:23

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

  int n;
  string s;
  while (cin >> n)
  {
    if (n == 0)
    {
      break;
    }
    cin >> s;

    int len = (int)s.size();
    int g = len / n;
    if (g == 1)
    {
      cout << s << endl;
      continue;
    }
    for (int i = 0; i < n; i++)
    {
      string r = s.substr(i * g, g);
      reverse(r.begin(), r.end());
      cout << r;
    }
    cout << endl;
  }

  return 0;
}
