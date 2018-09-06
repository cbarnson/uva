// Problem #    : 118
// Created on   : 2018-09-05 20:26:16

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

set<ii> fall;
string direction = "NESW";

int mx, my, fx, fy, fd;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

tuple<int, int> next(int x, int y) {
   return make_tuple(x + dx[fd], y + dy[fd]);
}

void process(string s) {

   for (auto &i : s) {
      if (i == 'F') {
	 int x, y;
	 tie(x, y) = next(fx, fy);
	 
	 if (x < 0 || y < 0 || x > mx || y > my) {

	    // previous robot has fallen here, we avoid
	    if (fall.count(ii(fx, fy)) > 0) 
	       continue;

	    // Fallen, remember this position for future robots
	    fall.insert(ii(fx, fy));
	    cout << fx << " " << fy << " " << direction[fd] << " LOST\n";
	    return;
	 }

	 // update values
	 fx = x, fy = y;
      } else {

	 // Right or left
	 fd = (i == 'R') ? (fd + 1) % 4 : (fd + 3) % 4;	 
      }
   }

   // Solution for this robot, who has not fallen
   cout << fx << " " << fy << " " << direction[fd] << "\n";
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> mx >> my;
   char c;
   string s;
   while (cin >> fx >> fy >> c >> s) {
      fd = direction.find(c);
      process(s);
   }

   return 0;
}
