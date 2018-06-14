// Problem #    : 10945
// Created on   : 2018-06-14 01:11:22

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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  while (getline(cin, s))
  {
    if (s == "DONE")
    {
      break;
    }

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    auto i = remove_if(s.begin(), s.end(), [](char c) {
      return !isalpha(c);
    });

    string r = string(s.begin(), i);
    if (equal(r.begin(), next(r.begin(), r.size() / 2), r.rbegin()))
    {
      cout << "You won't be eaten!\n";
    }
    else
    {
      cout << "Uh oh..\n";
    }
  }

  return 0;
}
