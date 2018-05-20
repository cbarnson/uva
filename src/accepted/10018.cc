// Problem #    : 10018
// Title        : Reverse and Add
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

unsigned int reverseInt(unsigned int x)
{
  string s = to_string(x);
  reverse(s.begin(), s.end());
  return (unsigned int)stoull(s);
}

bool isPalindrome(unsigned int x)
{
  string s = to_string(x);
  int len = s.length();
  if (len < 2)
  {
    return true;
  }

  for (int i = 0; i < len / 2; i++)
  {
    if (s[i] != s[len - i - 1])
    {
      return false;
    }
  }
  return true;
}

void test()
{
  cout << reverseInt(2132) << endl;
  cout << isPalindrome(9) << endl;
}

int main()
{
  int n;
  unsigned int x;
  cin >> n;
  while (n--)
  {
    cin >> x;
    int iter_count = 0;
    do
    {
      unsigned int y = reverseInt(x);
      x += y;
      iter_count++;
    } while (!isPalindrome(x));
    cout << iter_count << " " << x << endl;
  }

  return 0;
}
