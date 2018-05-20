// Problem #    : 136
// Title        : Ugly Numbers
// Accepted     : No
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

// A function to print all prime factors of a given number n
bool isUgly(int n)
{
  // Print the number of 2s that divide n
  while (n % 2 == 0)
  {
    // printf("%d ", 2);
    n = n / 2;
  }

  // n must be odd at this point.  So we can skip
  // one element (Note i = i +2)
  for (int i = 3; i <= sqrt(n); i = i + 2)
  {
    // While i divides n, print i and divide n
    while (n % i == 0)
    {
      // printf("%d ", i);
      if (!(i == 2 || i == 3 || i == 5))
      {
        return false;
      }
      n = n / i;
    }
  }

  // This condition is to handle the case when n
  // is a prime number greater than 2
  if (n > 2)
  {
    if (!(n == 2 || n == 3 || n == 5))
    {
      return false;
    }
  }
  // printf("%d ", n);

  return true;
}

void test()
{
  for (int i = 1; i <= 100000; i++)
  {
    cout << i << ": ";
    cout << isUgly(i) ? "yes" : "no";
    // primeFactors(i);
    cout << endl;
  }
}

int main()
{
  // template
  // test();

  int ugly_count = 0;
  int n = 0;
  do
  {
    // if (n > 100)
    //   break;

    n++;
    if (isUgly(n))
    {
      ugly_count++;
    }
  } while (ugly_count < 1500);

  cout << n << endl;

  return 0;
}
