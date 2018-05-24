// Problem #    : 673
// Created on   : 2018-05-23 21:43:24
// Title        : Parentheses Balance
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

int n, len;
string s;
stack<char> stk;

bool isYes(int i)
{
  if (i == len)
    return stk.empty();

  if (s[i] == '(' || s[i] == '[')
  {
    stk.push(s[i]);
    return isYes(i + 1);
  }

  if (stk.empty())
    return false;
  if (s[i] == ']' && stk.top() != '[')
    return false;
  if (s[i] == ')' && stk.top() != '(')
    return false;

  stk.pop();
  return isYes(i + 1);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> ws;
  while (n--)
  {
    getline(cin, s);
    len = (int)s.length();
    stk = stack<char>();
    if (isYes(0))
      cout << "Yes\n";
    else
      cout << "No\n";
  }

  return 0;
}
