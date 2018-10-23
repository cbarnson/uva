// Problem #    : 711a
// Created on   : 2018-10-23 09:51:05
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, r = 0;
   cin >> n;
   string s;

   vector<string> A;
   while (cin >> s) {      
      int i;
      if (!r && (i = s.find("OO")) != string::npos) {
	 s.replace(i, 2, "++");
	 r = 1;
      }
      A.push_back(s);
   }

   cout << (r ? "YES" : "NO") << endl;
   if (r)
      for (auto &x : A) cout << x << endl;
   


}
