// Problem #    : 488
// Created on   : 2018-05-29 19:47:02
// Title        : Triangle Wave
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

void print(int i, int a, int dx)
{
  if (i == 0)
    return;

  cout << string(i, (char)(i + '0')) << "\n";
  if (i == a)
  {
    dx = -1;
  }

  print(i + dx, a, dx);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int c, tc = 1;
  cin >> c;
  while (c--)
  {
    if (tc++ > 1)
    {
      cout << "\n";
    }

    int a, f;
    cin >> a >> f;

    for (int i = 0; i < f; i++)
    {
      print(1, a, 1);
      if (i < f - 1)
        cout << "\n";
    }
  }

  return 0;
}
