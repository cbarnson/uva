// Problem #    : 344
// Created on   : 2018-07-18 20:58:58

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

vector<int> key{100, 90, 50, 40, 10, 9, 5, 4, 1};
vector<string> val{"c", "xc", "l", "xl", "x", "ix", "v", "iv", "i"};

string roman(int n) {
  string ans = "";
  int i = 0;
  while (n > 0) {
    while (n >= key[i]) {
      n -= key[i];
      ans += val[i];
    }
    i++;
  }
  return ans;
}
int A[102][5];

void print(int i) {
  printf("%d i, %d v, %d x, %d l, %d c\n", A[i][0], A[i][1], A[i][2], A[i][3],
         A[i][4]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i < 102; i++)
    fill(A[i], A[i] + 5, 0);

  vector<string> dp;
  for (int i = 1; i <= 100; i++) {
    dp.push_back(roman(i));
  }

  string b = "ivxlc";
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 5; j++) {
      A[i][j] = count(dp[i].begin(), dp[i].end(), b[j]);
      if (i > 0) {
        A[i][j] += A[i - 1][j];
      }
    }
  }

  int n;
  while (cin >> n) {
    if (n == 0)
      break;
    printf("%d: ", n);
    print(n - 1);
  }

  return 0;
}
