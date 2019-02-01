// Problem #    : 4A
// Created on   : 2019-01-24 17:58:34
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#if __has_include("templates/default_cf.h")
#include "templates/default_cf.h"
#define DEBUG 1
#endif

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main() {
  ios_base::sync_with_stdio(false);
  CIN.tie(0);

  auto a = abs(-INT_MAX);
  int b = abs(INT_MIN);

  std::cout << a << endl << b << endl;
}