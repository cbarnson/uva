// Problem #    : 10340
// Created on   : 2018-05-23 21:17:30
// Title        : All in All
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

string a, b;

bool isSub(string &a, string &b, int i, int j)
{
  if (i == 0)
    return true;
  if (j == 0)
    return false;

  if (a[i - 1] == b[j - 1])
    return isSub(a, b, i - 1, j - 1);

  return isSub(a, b, i, j - 1);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> a >> b)
  {
    if (isSub(a, b, (int)a.length(), (int)b.length()))
      cout << "Yes\n";
    else
      cout << "No\n";
  }

  return 0;
}
