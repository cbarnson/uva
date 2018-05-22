// Problem #    : 11332
// Created on   : 2018-05-21 18:02:22
// Title        : Summing digits
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
typedef long long ll;

string ssum(string n)
{
  int ans = 0;
  for (auto &i : n)
  {
    ans += i - '0';
  }
  return to_string(ans);
}

int main()
{
  // template
  string n;
  while (cin >> n && n != "0")
  {

    do
    {
      n = ssum(n);
    } while ((int)n.length() > 1);

    cout << n << endl;
  }

  return 0;
}
