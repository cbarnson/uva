// Title        :
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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  char arr[110];
  scanf("%d\n", &n);
  while (n--)
  {
    scanf("0.%[0-9]...\n", &arr); // & is optional when arr is a char array
    printf("the digits are 0.%s\n", arr);
  }

  return 0;
}
