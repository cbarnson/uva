// Problem #    : binary_search
// Created on   : 2018-07-31 18:06:11

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

int binary_search(int A[], int l, int r, int x) {
   if (r >= l) {
      int m = l + (r - l) / 2;

      if (A[m] == x)
	 return m;

      if (A[m] > x) {
	 return binary_search(A, l, m-1, x);
      }
      return binary_search(A, m+1, r, x);
   }

   return -1;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int A[] = {1, 2, 5, 10, 20};
   int x;
   while (cin >> x) {
      int ans = binary_search(A, 0, 4, x);
      cout << ans << endl;
   }
  
   return 0;
}
