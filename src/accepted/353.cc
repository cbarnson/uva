// Problem #    : 353
// Created on   : 2018-06-16 05:15:51

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

bool isPalidrome(string s) {
  return equal(s.begin(), next(s.begin(), s.size() / 2), s.rbegin());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  while (getline(cin, s)) {
    cout << "The string ";
    if (s == "") {
      continue;
    }

    int len = (int)s.length();
    vector<vector<bool>> p(len + 1, vector<bool>(len, false));

    set<string> u;
    for (int i = 1; i < len + 1; i++) {
      for (int j = 0; j < len - i + 1; j++) {
        string b = s.substr(j, i);
        if (isPalidrome(b)) {
          u.insert(b);
        }
      }
    }

    cout << "'" << s << "' contains " << u.size() << " palindromes." << endl;
  }

  return 0;
}
