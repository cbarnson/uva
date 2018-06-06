// Problem #    : 256
// Created on   : 2018-06-05 21:15:03

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

vector<int> v[4];
int input[] = { 2, 4, 6, 8 };

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   string s = "999999999";
   for (int i = 0; i < 4; i++) {
      int d = input[i];
      int half_d = d / 2;
      string s2 = s.substr(0, half_d);
      stringstream ss(s2);
      int len = 0;
      ss >> len;
      int power = pow(10, half_d);
      for (int hi = 0; hi <= len; hi++) {
	 for (int lo = 0; lo <= len; lo++) {
	    int n = (hi * power) + lo;
	    int s = hi + lo;
	    if (s * s == n) {
	       v[half_d-1].push_back(n);
	    }
	 }
      }
   }

   int n;
   while (cin >> n) {
      int nn = (n / 2) - 1;
      for (int i = 0; i < (int)v[nn].size(); i++) {
	 cout << right << setw(n) << setfill('0') << v[nn][i] << endl;       
      }    
   }

   return 0;
}
