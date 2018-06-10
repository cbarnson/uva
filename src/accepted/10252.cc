// Problem #    : 10252
// Created on   : 2018-06-09 22:59:41

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

void countLC(vector<int> &v, string s) {
  for_each(s.begin(), s.end(), [&](char c) {
    if (islower(c)) {
      v[(int)(c - 'a')] += 1;
    }
  });
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string a, b;
  while (getline(cin, a) && getline(cin, b)) {
    string c = "";
    vi va(26, 0);
    vi vb(26, 0);
    vi vc(26, 0);
    countLC(va, a);
    countLC(vb, b);

    for (int i = 0; i < 26; i++) {
      vc[i] = min(va[i], vb[i]);
      if (vc[i] > 0) {
        c += string(vc[i], (char)(i + 'a'));
      }
    }

    cout << c << endl;
  }

  return 0;
}
