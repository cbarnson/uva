// Problem #    : b
// Created on   : 2018-09-08 10:48:10

#include <bits/stdc++.h>

#define ALL(c) (c).begin(), (c).end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())

using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

string g[101];
string ans[101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  while (cin >> n >> m) {
     
     fill(g, g+101, "");
     fill(ans, ans+101, "");
     for (int i = 0; i < n; i++) {
	cin >> g[i];
     }
     int c = 0;
     for (int j = 0; j < m; j++) {
	int i;
	for (i = 0; i < n - 1; i++) {

	   string s1 = ans[i] + g[i][j];
	   string s2 = ans[i+1] + g[i+1][j];
	   if (s1 > s2) {
	      c++;
	      break;
	   }
	}
	if (i == n-1) {
	   for (i = 0; i < n; i++) {
	      ans[i] += g[i][j];
	   }
	}
     }

     cout << c <<endl;
  }

  return 0;
}
