// Problem #    : 10424
// Created on   : 2018-06-02 18:49:47

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  char c;
  int n = 0;
  string a, b;
  while (getline(cin, a) && getline(cin, b)) {
    int sum_a = 0, sum_b = 0;

    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);

    for (auto&& i : a) {
      if (isalpha(i)) {
        sum_a += (int)(i - 'a') + 1;
      }
    }

    for (auto&& i : b) {
      if (isalpha(i)) {
        sum_b += (int)(i - 'a') + 1;
      }
    }

    while (sum_a >= 10) {
      int aa = sum_a;
      sum_a = 0;
      while (aa > 0) {
        sum_a += (aa % 10);
        aa /= 10;
      }
    }

    while (sum_b >= 10) {
      int bb = sum_b;
      sum_b = 0;
      while (bb > 0) {
        sum_b += (bb % 10);
        bb /= 10;
      }
    }

    double r = (double)min(sum_a, sum_b) / (double)max(sum_a, sum_b);
    cout << setprecision(2) << fixed << r * 100 << " %\n";
  }

  return 0;
}
