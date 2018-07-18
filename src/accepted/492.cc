// Problem #    : 492
// Created on   : 2018-07-17 22:46:46

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

ostream &operator<<(ostream &os, ii &p) {
  os << "(" << p.first << ", " << p.second << ")\n";
}

ostream &operator<<(ostream &os, vi &v) {
  for (auto &i : v)
    os << i << " ";
  os << endl;
}
ostream &operator<<(ostream &os, vector<char> &v) {
  for (auto &i : v)
    os << i << " ";
  os << endl;
}

string vowel = "aeiouAEIOU";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string w = "";
  char c;
  while (cin.get(c)) {
    if (isalpha(c)) {
      w += c;
    } else {
      if (!w.empty() && vowel.find(w.front()) != string::npos) {
        cout << w << "ay";
      } else {
        if (w.length() > 1) {
          cout << w.substr(1, w.length() - 1) << w.front() << "ay";
        } else if (w.length() > 0) {
          cout << w << "ay";
        }
      }
      cout << c;
      w = "";
    }
  }

  return 0;
}
