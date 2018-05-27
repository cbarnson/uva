// Problem #    : 10921
// Created on   : 2018-05-26 19:39:12
// Title        : Find the Telephone
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

string k = "ABCDEFGHIJKLMNOPQRSTUVWXYZ-0123456789";
string v = "22233344455566677778889999-0123456789";

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  char c;
  while (cin.get(c))
  {
    if (c == '\n')
      cout << c;
    auto i = k.find(c);
    if (i != string::npos)
      cout << v[i];
  }

  return 0;
}
