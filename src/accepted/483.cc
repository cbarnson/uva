// Problem #    : 483
// Created on   : 2018-05-27 12:31:03
// Title        : Word Scramble
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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string l, s;
  while (getline(cin >> ws, l))
  {
    stringstream ss(l);
    while (ss >> s)
    {
      cout << string(s.rbegin(), s.rend());
      cout << ((ss.eof()) ? "\n" : " ");
    }
  }

  return 0;
}
