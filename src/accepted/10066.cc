// Problem #    : 10066
// Created on   : 2018-07-17 19:10:14

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

#define sz(a) (int)a.size()

typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints
typedef vector<vii> vvii;  // 2d vector of pairs
typedef vector<bool> vb;   // 1d vector of bools
typedef long long ll;

const int MM = 102;

int LCS(int A[], int n, int B[], int m) {
  int L[MM + 1][MM + 1];
  int i, j, k;

  for (i = n; i >= 0; i--) {
    for (j = m; j >= 0; j--) {
      if (i == n || j == m) {
        L[i][j] = 0;
      } else if (A[i] == B[j]) {
        L[i][j] = 1 + L[i + 1][j + 1];
      } else {
        L[i][j] = max(L[i + 1][j], L[i][j + 1]);
      }
    }
  }

  return L[0][0];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int A[MM], B[MM];

  int m, n, tc = 1;
  while (cin >> m >> n) {
    if (m == 0 && n == 0)
      break;

    for (int i = 0; i < m; i++)
      cin >> A[i];
    for (int i = 0; i < n; i++)
      cin >> B[i];

    int len = LCS(A, m, B, n);
    cout << "Twin Towers #" << tc++ << endl << "Number of Tiles : ";
    cout << len << endl << endl;
  }

  return 0;
}
