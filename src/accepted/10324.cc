// Problem #    : 10324
// Created on   : 2018-06-13 23:36:53

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
  string s = "";
  int tc = 1;
  while (getline(cin >> ws, s))
  {
    if (s == "")
    {
      break;
    }
    cout << "Case " << tc++ << ":\n";

    vector<int> v;
    int i, l = 0, len = (int)s.length();
    for (i = 1; i < len; i++)
    {
      if (s[i] != s[l])
      {
        for (int j = 0; j < (i - l); j++)
        {
          v.push_back(i - 1);
        }
        l = i;
      }
    }

    for (int j = 0; j < (i - l); j++)
    {
      v.push_back(i - 1);
    }
    l = i;

    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> x >> y;
      if (v[x] == v[y])
      {
        cout << "Yes\n";
      }
      else
      {
        cout << "No\n";
      }
    }
  }

  return 0;
}
