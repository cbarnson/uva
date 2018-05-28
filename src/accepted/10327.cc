// Problem #    : 10327
// Created on   : 2018-05-27 17:52:48
// Title        : Flip sort
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

  int n;
  int a[1001];
  while (cin >> n)
  {
    for (int i = 0; i < n; i++)
      cin >> a[i];

    bool d = false;
    int cnt = 0;
    while (!d)
    {
      d = true;
      for (int i = 0; i < n - 1; i++)
      {
        if (a[i + 1] < a[i])
        {
          int tmp = a[i];
          a[i] = a[i + 1];
          a[i + 1] = tmp;
          cnt++;
          d = false;
        }
      }
    }

    printf("Minimum exchange operations : %d\n", cnt);
  }

  return 0;
}
