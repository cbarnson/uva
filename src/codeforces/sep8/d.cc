// Problem #    : d
// Created on   : 2018-09-08 11:56:06

#include <bits/stdc++.h>

#define ALL(c) (c).begin(), (c).end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())

using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, a;
  
  
  while (cin >> n) {
     vi ans;
     int j = 0;
     for (int i = 0; i < n; i++) {
	cin >> a;
	if (i && a == 1) {
	   ans.push_back(i - j), j = i;
	}
     }
     ans.push_back(n - j);
     
     cout << (int)ans.size() << endl;
     for (int i = 0; i < (int)ans.size(); i++) {
	cout << ans[i] << " \n"[i == (int)ans.size() - 1];
     }

	
  }
  
  return 0;
}
