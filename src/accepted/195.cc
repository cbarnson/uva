// Problem #    : 195
// Created on   : 2018-07-21 16:54:59

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

// string comparison where capitals of corresponding letter
// come before lowercase, and lowercase letters before uppercase letters, where
// the uppercase letter's lowercase equivalent comes later in the alphabetic
// sequence
bool cmp(char a, char b) {
  if (isupper(a) && islower(b)) {
    return tolower(a) <= b;
  } else if (islower(a) && isupper(b)) {
    return a < tolower(b);
  }
  return a < b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  string s;
  while (n--) {
    cin >> s;
    // must do both in initial sort and next_perm
    sort(s.begin(), s.end(), cmp);
    cout << s << endl;
    while (next_permutation(s.begin(), s.end(), cmp)) {
      cout << s << endl;
    }
  }

  return 0;
}
