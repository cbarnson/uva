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

void fastscan(int &number)
{
  //variable to indicate sign of input number
  bool negative = false;
  register int c;

  number = 0;

  // extract current character from buffer
  c = getchar();
  if (c == '-')
  {
    // number is negative
    negative = true;

    // extract the next character from the buffer
    c = getchar();
  }

  // Keep on extracting characters if they are integers
  // i.e ASCII Value lies from '0'(48) to '9' (57)
  for (; (c > 47 && c < 58); c = getchar())
    number = number * 10 + c - 48;

  // if scanned input has a negative sign, negate the
  // value of the input number
  if (negative)
    number *= -1;
}

// https://www.geeksforgeeks.org/getchar_unlocked-faster-input-cc-competitive-programming/
// similar to getchar(), except it is NOT thread safe
// Since it is not thread safe, all overheads of mutual exclusion are avoided and it is faster than getchar()
// There is no issue with using getchar_unlocked() even in multithreaded environment as long as the thread using it is the only thread accessing file object
// One more difference with getchar() is, it is not a C standard library function, but a POSIX function. It may not work on Windows based compilers.
// It is a known fact than scanf() is faster than cin and getchar() is faster than scanf() in general. getchar_unlocked() is faster than getchar(), hence fastest of all.
// Similarly, there are getc_unlocked() putc_unlocked(), and putchar_unlocked() which are non-thread-safe versions of getc(), putc() and putchar() respectively.
void demoGetCharUnlocked()
{
  // Syntax is same as getchar()
  char c;
  // c = getchar_unlocked();

  printf("Entered character is %c", c);
}

// Function Call
int main()
{
  int number;
  fastscan(number);
  cout << number << "\n";
  return 0;
}
