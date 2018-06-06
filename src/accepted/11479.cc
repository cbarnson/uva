// Problem #    : 11479
// Created on   : 2018-06-05 23:06:30

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll a, b, c, t, tc = 1;
  cin >> t;
  while (t--) {
     cout << "Case " << tc++ << ": ";


     cin >> a >> b >> c;
     set<ll> s;
     s.insert(a);
     s.insert(b);
     s.insert(c);

     if (a < 0 || b < 0 || c < 0) {
	cout << "Invalid\n";
	continue;
     }
     
     if (a + b <= c || b + c <= a || a + c <= b) {
	cout << "Invalid\n";
     } else if (s.size() == 3) {
	cout << "Scalene\n";	
     } else if (s.size() == 2) {
	cout << "Isosceles\n";
     } else {
	cout << "Equilateral\n";
     }
	
  }
  
  
  return 0;
}
