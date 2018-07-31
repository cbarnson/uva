// Problem #    : 112
// Created on   : 2018-07-30 19:02:38

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

int ans;
int soln(int s, int t, char *c) {
  int f = 0, l = 0, x, n;
  while (isspace(*c)) {
    *c = getchar();
  }

  if (*c == '(') {
    x = f = 0, n = 1;
    while (*c = getchar()) {
      if (isdigit(*c)) {
        x = x * 10 + *c - '0', f = 1;
      } else {
        if (*c == '-') {
          n = -1;
        } else {
          break;
        }
      }
    }

    while (isspace(*c))
      *c = getchar();
    x *= n;

    if (f == 0) {
      return 0;
    }

    int L = soln(s + x, t, c);
    while ((*c = getchar()) != '(')
      ;
    int R = soln(s + x, t, c);
    while ((*c = getchar()) != ')')
      ;
    if (L == 0 && R == 0) {
      if (s + x == t) {
        ans = 1;
      }
    }
    return 1;
  }
}

int main() {

  char c;
  int t;
  while (scanf("%d", &t) == 1) {
    ans = 0;
    c = getchar();
    soln(0, t, &c);
    if (ans) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }

  return 0;
}
