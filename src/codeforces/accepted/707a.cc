// Problem #    : 707a
// Created on   : 2018-10-21 17:07:28
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, m;
   cin >> n >> m;

   string s = "CMY";
   FR(i, n) {
      FR(j, m) {
	 char c; cin >> c;
	 if (s.find(c) != string::npos) {
	    cout << "#Color" << endl;
	    return 0;
	 }
      }
   }

   cout << "#Black&White" << endl;
	 
   


}
