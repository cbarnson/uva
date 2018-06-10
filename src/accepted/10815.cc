// Problem #    : 10815
// Created on   : 2018-06-10 00:26:34

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

string getWord() {
  char c;
  string s = "";
  while (cin.get(c)) {
    if (isalpha(c)) {
      s += c;
      while (cin.get(c)) {
        if (isalpha(c)) {
          s += c;
        } else {
          break;
        }
      }
      break;
    }
  }
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s = "";
  set<string> dict;
  while (s = getWord(), s != "") {
    dict.insert(s);
  }

  for (auto &i : dict) {
    cout << i << endl;
  }

  return 0;
}
