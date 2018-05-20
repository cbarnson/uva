// Problem #    : 10035
// Title        : Primary Arithmetic
// Accepted     : No
// Date         : 20180519

#include <algorithm>
#include <assert.h>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vec2d;
typedef vector<ll> vi;

ll countDigits(ll n) { return n > 0 ? (ll)log10((double)n) + 1 : 1; }

ll digitAt(ll x, ll i) { return (ll)(x / pow(10, i)) % 10; }

ll sumAt(ll a, ll b, ll i) { return digitAt(a, i) + digitAt(b, i); }

int main() {

  ll a, b;

  while (cin >> a >> b) {

    if (a == 0 && b == 0) {
      break;
    }

    ll num_digits = countDigits(max(a, b));
    vi c(num_digits + 1, 0);
    vi res(num_digits + 1, 0);

    ll i;
    for (i = 0; i < num_digits; i++) {
      ll ans = sumAt(a, b, i) + c[i];
      if (ans >= 10) {
        c[i + 1] = 1;
        ans %= 10;
      }

      res[i] = ans;
    }

    // last carry
    res[i] = c[i];

    // count carries
    ll carry_count = count(c.begin(), c.end(), 1);

    // output
    if (carry_count == 0) {
      cout << "No carry operation.";
    } else if (carry_count == 1) {
      cout << "1 carry operation.";
    } else {
      cout << carry_count << " carry operations.";
    }

    cout << endl;
  }

  return 0;
}
