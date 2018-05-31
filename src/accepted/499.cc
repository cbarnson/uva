// Problem #    : 499
// Created on   : 2018-05-30 23:12:26
// Title        : What's The Frequency, Kenneth?
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string l;
  while (getline(cin, l)) {
    int a[26 * 2] = {0};

    for_each(l.begin(), l.end(), [&](char c) {
      if (c >= 'a' && c <= 'z') {
        a[(int)(c - 'a') + 26]++;
      } else if (c >= 'A' && c <= 'Z') {
        a[(int)(c - 'A')]++;
      }
    });

    auto it = max_element(a, a + (26 * 2));

    for (int i = 0; i < 26 * 2; i++) {
      if (a[i] == *it) {
        if (i < 26) {
          cout << (char)(i + 'A');
        } else {
          cout << (char)(i + 'a' - 26);
        }
      }
    }
    cout << " " << *it << endl;
  }

  return 0;
}
