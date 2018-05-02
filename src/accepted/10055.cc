//================================
//UVA problem#: 10055
//CPSC 3200,	2017-01-13
//Cody Barnson,	ID#001172313
//================================
#include <bits/stdc++.h>
using namespace std;

int main() {

  // input values will be no greater than 2^32
  // Using numeric_limits<int>::max() will show the max value that can be
  // stored in an 'int' (2,147,483,647) on this machine, so we cannot use it.
  // unsigned long (4,294,967,295) with some c++ standard is also
  // unacceptable, because it is (2^32)-1 (too small).

  // To be safe, we can use any of the long long data types, which are
  // guaranteed to be at least 64 bits wide in all data models. 
  long long x, y;
  while (cin >> x >> y) {
    // using the signed variant of ll and doing a check for negative
    // is better than using unsigned ll and doing a max and min check
    long long ans = y - x;
    if (ans < 0) ans = ans * (-1);
    cout << ans << endl;
  }
  return 0;
}
