// Problem #    : 10591
// Created on   : 2018-07-21 16:35:24

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

typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints
typedef vector<vii> vvii;  // 2d vector of pairs
typedef vector<bool> vb;   // 1d vector of bools
typedef long long ll;

ostream &operator<<(ostream &os, vi &v) {
  for (auto &i : v)
    os << i << " ";
  os << endl;
}

vi digitsSquared(int n) {
  vi ans;
  if (n == 0) {
    ans.push_back(0);
    return ans;
  }
  while (n > 0) {
    int x = n % 10;
    ans.push_back(x * x);
    n /= 10;
  }
  return ans;
}

ll squareSum(ll n) {
  if (n == 0) {
    return 0;
  }
  ll sum = 0;
  while (n > 0) {
    ll x = n % 10;
    sum += x * x;
    n /= 10;
  }
  return sum;
}

set<int> seen;
bool isHappy(ll n, ll init, bool first = false) {

  if (seen.count((int)n) > 0) {
    return false;
  } else {
    seen.insert((int)n);
  }

  if (first && n != 1) {
    return isHappy(squareSum(n), init);
  }

  if (n == 1) {
    return true;
  } else if (n == init) {
    return false;
  } else {
    return isHappy(squareSum(n), init);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, tc = 1;
  cin >> n;
  while (n--) {
    ll m;
    cin >> m;
    cout << "Case #" << tc++ << ": " << m << " is ";
    seen.clear();
    if (isHappy(m, m, true)) {
      cout << "a Happy number." << endl;
    } else {
      cout << "an Unhappy number." << endl;
    }
  }

  return 0;
}
