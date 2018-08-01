// Problem #    : 10341
// Created on   : 2018-07-31 18:32:23

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

typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints
typedef vector<vii> vvii;  // 2d vector of pairs
typedef vector<bool> vb;   // 1d vector of bools
typedef long long ll;

ostream &operator<<(ostream &os, vi &v) {
   for (auto &i : v)
      os << i << " ";
   os << endl;
}

#define EPS 1e-7

int p,q,r,s,t,u;

double f(double x) {
   return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double bisection() {
   double lo = 0, hi = 1;
   while (lo + EPS < hi) {
      double m = (lo + hi) / 2;
      if (f(m) * f(lo) <= 0) {
	 hi = m;
      } else {
	 lo = m;
      }
   }
   return (lo + hi) / 2;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   while (scanf("%d %d %d %d %d %d ", &p, &q, &r, &s, &t, &u) != EOF) {
      if (f(0) * f(1) > 0) 
	 printf("No solution\n");
      else
	 printf("%.4lf\n", bisection());
   }
  
   return 0;
}
