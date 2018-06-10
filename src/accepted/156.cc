// Problem #    : 156
// Created on   : 2018-06-09 19:32:13

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

void count(string s, vector<int>& arr) {
  for_each(s.begin(), s.end(), [&](char c) {
    if (isupper(c)) {
      arr[(int)(c - 'A')] += 1;
    } else if (islower(c)) {
      arr[(int)(c - 'a')] += 1;
    }
  });
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string l;

  vector<string> keys;
  vector<vector<int>> v;

  // organize into arrays of length 26, representing a count of each
  // corresponding character
  while (getline(cin, l) && l != "#") {
    stringstream ss(l);
    string s;
    while (ss >> s) {
      vector<int> a(26, 0);
      count(s, a);
      v.push_back(a);
      keys.push_back(s);
    }
  }

  // compare count arrays for matches, if none found add to our results list
  vector<string> ans;
  for (int i = 0; i < (int)v.size(); i++) {
    bool match = false;
    for (int j = 0; j < (int)v.size(); j++) {
      if (i == j) {
        continue;
      }
      if (v[i] == v[j]) {
        match = true;
        break;
      }
    }
    if (!match) {
      ans.push_back(keys[i]);
    }
  }

  // want sorted by strings
  sort(ans.begin(), ans.end());
  for (auto& i : ans) {
    cout << i << endl;
  }

  return 0;
}
