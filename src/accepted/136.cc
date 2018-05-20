// Problem #    : 136
// Title        : Ugly Numbers
// Accepted     : Yes
// Date         : 20180520

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
  // template
  const int NN = 1500;
  int DP[NN] = {1}, t2 = 0, t3 = 0, t5 = 0, tmp, i;
  for (i = 1; i < NN; i++)
  {
    while (DP[t2] * 2 <= DP[i - 1])
      t2++;
    while (DP[t3] * 3 <= DP[i - 1])
      t3++;
    while (DP[t5] * 5 <= DP[i - 1])
      t5++;

    // printf("i = %d, t2 = %d, t3 = %d, t5 = %d\n", i, t2, t3, t5);

    tmp = DP[t2] * 2;
    if (DP[t3] * 3 < tmp)
      tmp = DP[t3] * 3;
    if (DP[t5] * 5 < tmp)
      tmp = DP[t5] * 5;
    DP[i] = tmp;
  }
  printf("The 1500'th ugly number is %d.\n", DP[NN - 1]);

  return 0;
}
