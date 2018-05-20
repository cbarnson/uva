// Problem #    : 10370
// Title        : Above Average
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

  int c, n;
  cin >> c;
  while (c--)
  {
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    // average
    double avg = 0.0;
    for_each(a.begin(), a.end(), [&](double d) { avg += d; });
    avg /= n;

    int above = count_if(a.begin(), a.end(), [=](double d) { return d > avg; });
    cout << setprecision(3) << fixed << 100.0 * (double)above / (double)n << "%" << endl;

    // cout << avg << ", " << above << endl;
  }

  return 0;
}
