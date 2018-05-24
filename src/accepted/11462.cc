// Problem #    : 11462
// Created on   : 2018-05-23 20:31:10
// Title        : Age Sort
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

int a[2000010];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n && n != 0)
  {
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++)
      cout << a[i] << " \n"[i == n - 1];
  }

  return 0;
}
