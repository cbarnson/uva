// Problem #    : 101
// Created on   : 2018-05-21 19:48:19
// Title        :
// Accepted     : No

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
typedef vector<ii> vii;
typedef long long ll;

void printHeight(vi &h)
{
  int w = 6;
  for (int i = 0; i < (int)h.size(); i++)
  {
    cout << setw(w) << "h[" + to_string(i) + "]";
  }
  cout << endl
       << string("-", w * (int)h.size());
  for (int i = 0; i < (int)h.size(); i++)
  {
    cout << setw(w) << h[i];
  }
  cout << endl;
}

void print(vii &a, vi &h)
{
  int w = 6;
  for (auto &i : a)
  {
    cout << setw(w) << fixed << "(" << i.first << ", " << i.second << ")"
         << " ";
  }
  cout << endl;

  printHeight(h);
}

int timestamp = 1;
int ts()
{
  return timestamp++;
}

bool isLegal(vii &a, vi &h, int i, int j)
{
  if (i == j)
    return false;
  if (a[i].first == a[j].first)
    return false;
  return true;
}

// take 'from'th element, existing in position a[from].first, update it's position to 'to'
void move(vii &a, vi &h, int from, int to)
{
  h[a[from].first]--;
  a[from].first = to;
  h[to]++;
  a[from].second = ts();
}

void clean(vii &a, vi &h, int i)
{
  if (h[i] < 2)
  {
    cout << "h[" << i << "] = " << h[i] << ", which is < 2, no clean needed\n";
    return;
  }

  for (int j = 0; j < (int)a.size(); j++)
  {
    printf("j = %d, a[j].first = %d, i = %d\n", j, a[j].first, i);
    if (i == j && a[j].first == i)
      continue;
    if (a[j].first == i)
    {
      cout << "moving " << j << endl;
      move(a, h, j, j);
    }
  }
  printf("finished clean of i = %d\n", i);
}

void moveOnto(vii &a, vi &h, int i, int j)
{
  clean(a, h, i);
  clean(a, h, j);

  move(a, h, i, j);
}

void moveOver(vii &a, vi &h, int i, int j)
{
  clean(a, h, i);
}

void pileOnto(vii &a, vi &h, int i, int j)
{
  clean(a, h, j);
}

void pileOver(vii &a, vi &h, int i, int j)
{
}

void printOutput(vii &a)
{
  vector<vector<ii>> ans((int)a.size());

  for (int i = 0; i < (int)a.size(); i++)
  {
    ans[a[i].first].push_back(make_pair(a[i].second, i));
  }

  // sort each inner vec and print
  int i = 0;
  for (auto &k : ans)
  {
    cout << i++ << ": ";
    sort(k.begin(), k.end());
    for (auto &p : k)
    {
      cout << p.second << " ";
    }
    cout << endl;
  }
}

int main()
{

  int n;
  cin >> n;

  vii a(n);
  vi h(n, 1);
  for (int i = 0; i < n; i++)
  {
    a[i].first = i;
    a[i].second = 0;
  }

  print(a, h);
  printOutput(a);

  string s1, s2;
  int i, j;
  cin >> s1;
  while (s1 != "quit")
  {
    cin >> i >> s2 >> j;
    if (!isLegal(a, h, i, j))
    {
      cout << "move is not legal" << endl;
      continue;
    }
    else
    {
      cout << "move is legal" << endl;
    }
    if (s1 == "move")
    {
      if (s2 == "onto")
      {
        moveOnto(a, h, i, j);
      }
      else
      {
        moveOver(a, h, i, j);
      }
    }
    else
    {
      if (s2 == "onto")
      {
        pileOnto(a, h, i, j);
      }
      else
      {
        pileOver(a, h, i, j);
      }
    }

    print(a, h);
    printOutput(a);
    // next instruction
    cin >> s1;
  }

  return 0;
}
