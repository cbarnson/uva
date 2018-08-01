// Problem #    : 167
// Created on   : 2018-07-31 23:27:32

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

int A[8][8];

void read() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> A[i][j];
    }
  }
}

int sum(vi &B) {
  int s = 0;
  for (int i = 0; i < 8; i++) {
    s += A[i][B[i]];
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // find solutions, only need to do this once.
  vvi s;
  vi B(8);
  iota(B.begin(), B.end(), 0);
  do {
    for (int i = 0; i < 7; i++) {
      for (int j = i + 1; j < 8; j++) {
        // By virtue of how our data is represented in a 1D array, we don't need
        // to check each queen is on a different row; and by examining
        // permutations only, don't need to check each queen is on a different
        // column, so only need to check if any pair of queen share a diagonal,
        // which is easily checked by comparing the row diff and col diff (if
        // match, share diag).
        if (abs(i - j) == abs(B[i] - B[j])) {
          goto next;
        }
      }
    }

    // this is a potential solution, save for later.
    s.push_back(vi(B));

  next:;

  } while (next_permutation(B.begin(), B.end()));

  int n;
  cin >> n;
  while (n--) {
    read();

    // using our precomputed solutions, compute the score of each one, take the
    // best. Small input, so this is fine.
    int best = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      best = max(best, sum(s[i]));
    }
    cout << setw(5) << best << endl;
  }

  return 0;
}
