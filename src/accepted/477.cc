// Problem #    : 477
// Created on   : 2018-09-05 19:53:47

#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, c)							\
   for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define SZ(x) ((int)((x).size()))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints
typedef vector<vii> vvii;  // 2d vector of pairs

pair<char, double[4]> S[10];


int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   string s;
   int i = 0;
   while (getline(cin, s)) {
      if (s == "*") break;

      stringstream ss(s);
      ss >> S[i].first;
      REP(j, 3) {
	 ss >> S[i].second[j];
      }
      if (S[i].first == 'r')
	 ss >> S[i].second[3];

      i++;
   }

   int k = 0;
   while (getline(cin, s)) {
      k++;
      double x, y;
      stringstream ss(s);
      ss >> x >> y;
      if (x == 9999.9 && y == 9999.9) break;

      int c = 0;

      // i is the number of shapes in our graph, 'j' is the # of the shape
      REP(j, i) {

	 if (S[j].first == 'r') {

	    if (x >= S[j].second[0] && x <= S[j].second[2] && y <= S[j].second[1] && y >= S[j].second[3]) {
	       cout << "Point " << k << " is contained in figure " << j + 1 << "\n";
	       c++;
	    } 
	    
	 } else {

	    if (hypot(x - S[j].second[0], y - S[j].second[1]) <= S[j].second[2]) {
	       cout << "Point " << k << " is contained in figure " << j + 1 << "\n";
	       c++;	       
	    }
	    
	 }
	 
      }
      if (c == 0) {
	 cout << "Point " << k << " is not contained in any figure\n";
      }
   }
  
   return 0;
}
