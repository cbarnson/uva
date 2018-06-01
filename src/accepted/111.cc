// Problem #    : 111
// Created on   : 2018-05-31 18:26:29
// Title        : History Grading
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

const int NN = 21;

// longest common subsequence
// Shorter implementation of Howard's common_subseq.cc algorithm, without the
// resulting LCS part.
int lcs(int A[], int n, int B[], int m) {
  int dp[NN + 1][NN + 1];

  for (int i = n; i >= 0; i--) {
    for (int j = m; j >= 0; j--) {
      if (i == n || j == m) {
        dp[i][j] = 0;
      } else if (A[i] == B[j]) {
        dp[i][j] = 1 + dp[i + 1][j + 1];
      } else {
        dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }

  return dp[0][0];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // single output problem!  Don't be misled by the sample input/output
  int n;
  while (cin >> n) {
    // Note: for each line containing n integers, representing the 'events'
    // labeled from 1, 2, ... n, the ith value read in RK_i, where (1 <= i <=
    // n), represents the 'RANK' of the ith 'event' in the correct chronological
    // sequence. so, for example the line of values: 4 2 3 1
    //
    // is better represented as follows:
    // eventID: 1 2 3 4
    // rank   : 4 2 3 1
    // order  : 4 2 3 1
    //
    // But, rank and order are not necessarily the same, note:
    // e.g.
    // 3 1 2 4 9 5 10 6 8 7
    //
    // eventID: 1  2  3  4  5  6  7  8  9 10
    // rank   : 3  1  2  4  9  5 10  6  8  7
    // order  : 2  3  1  4  6  8 10  9  5  7
    //
    // note how the order, is the translation: "event 1 goes 3rd, event 2 goes
    // 1st, ..."
    int A[NN], B[NN];
    for (size_t i = 0; i < n; i++) {
      int rk;
      cin >> rk;
      A[rk - 1] = i;
    }

    int tmp;
    while (cin >> tmp) {
      B[tmp - 1] = 0;
      for (size_t i = 1; i < n; i++) {
        int rk;
        cin >> rk;
        B[rk - 1] = i;
      }

      cout << lcs(A, n, B, n) << endl;
    }
  }

  return 0;
}
