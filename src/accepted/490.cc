// Problem #    : 490
// Created on   : 2018-05-30 21:40:40
// Title        : Rotating Sentences
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

string s[101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n = 0, mlen = 0;
  string l;
  while (getline(cin, l)) {
    mlen = max(mlen, (int)l.length());
    s[n++] = l;
  }

  for (int j = 0; j < mlen; j++) {
    for (int i = n - 1; i >= 0; i--) {
      if (j < ((int)s[i].length())) {
        cout << s[i][j];
      } else {
        cout << ' ';
      }
    }
    cout << "\n";
  }

  return 0;
}
