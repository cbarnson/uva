// Problem #    : enum_combinations
// Created on   : 2018-07-30 18:39:11

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

int C(int n, int k, vi &A) {
  // Trick: initialize a vector of k 1's, then resize to 'n' and fill with 0's
  // use next_permutation (in reverse) to "bitmask" and enumerate all options
  vi b(k, 1);
  b.resize(n, 0);

  // very basic, store count
  int cnt = 0;

  do {

    // pass over all n items, take/save/print the ones that match the "bitmask"
    for (int i = 0; i < n; i++) {
      if (b[i]) {
        cout << A[i] << " ";
      }
    }
    cnt++;
    cout << endl;

  } while (next_permutation(b.rbegin(), b.rend()));

  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
