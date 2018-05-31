// Problem #    : 10405
// Created on   : 2018-05-30 18:05:55
// Title        : Longest Common Subsequence
// Accepted     : Yes

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

// modification on Needleman-Wunsch
// mismatches are -INF (or in this case, -1000000000 is enough)
// matches are 1, and insertion or deletion is 0 (for LCS only)

// aside: for doing regular Needleman-Wunsch string alignment, you might use:
// MISMATCH = -1
// MATCH    = +2
// INDEL    = -1
const int MISMATCH = -10000000;
const int MATCH = 1;
const int INDEL = 0;

// Note: since the input comes in the form of 2 **LINES**, which may contain
// spaces (i.e. ' ') we can't use a literal ' ' to check against, instead, since
// we know when an INDEL occurs, just inline the INDEL const, then just do char
// comparison inline as well (in our function 'f' below). Thus, the 'score'
// function is unused and not needed.
int score(char c1, char c2) {
  if (c1 == ' ' || c2 == ' ') {
    return INDEL;
  } else if (c1 == c2) {
    return MATCH;
  }
  return MISMATCH;
}

// at most 1000 characters
const int NN = 1001;

// memorization table
int dp[NN][NN];
string a, b;

// Recurrence
int f(int i, int j) {
  // base cases
  if (i == 0 && j == 0) {
    return 0;
  } else if (j == 0) {
    return i * INDEL;
    // return i * score(a[i], ' ');
  } else if (i == 0) {
    return j * INDEL;
    // return j * score(' ', b[i]);
  }

  // note: in book describes string alignment algo from a[1..n] and b[1..m]
  // (1-based indices) so we account for that here
  // int opt1 = f(i - 1, j - 1) + score(a[i - 1], b[j - 1]);
  // int opt2 = f(i - 1, j) + score(a[i - 1], ' ');
  // int opt3 = f(i, j - 1) + score(' ', b[i - 1]);

  int opt1 = dp[i - 1][j - 1] + ((a[i - 1] == b[j - 1]) ? MATCH : MISMATCH);
  int opt2 = dp[i - 1][j] + INDEL;
  int opt3 = dp[i][j - 1] + INDEL;
  return max(opt1, max(opt2, opt3));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (getline(cin, a) && getline(cin, b)) {
    int ii = (int)a.length();
    int jj = (int)b.length();

    // note: the 1000 + 1 sizing on dp[][] to account for 1-based-ness
    for (int i = 0; i <= ii; i++) {
      for (int j = 0; j <= jj; j++) {
        if (i == 0 || j == 0) {
          dp[i][j] = f(i, j);
        }
      }
    }

    // solve using bottom-up DP
    for (int i = 1; i <= ii; i++) {
      for (int j = 1; j <= jj; j++) {
        dp[i][j] = f(i, j);
      }
    }

    // answer (note: depending on values you set for MATCH/MISMATCH/INDEL, this
    // bottom right corner cell value could be edit distance or lcs; in our
    // case, it is lcs, because we do not consider MISMATCH's at all, due to the
    // -1 billion value)
    int lcs = dp[ii][jj];
    cout << lcs << endl;
  }

  return 0;
}
