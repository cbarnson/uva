// Problem #    : 520a
// Created on   : 2018-10-14 16:24:43
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   string s;
   cin >> n >> s;
   transform(begin(s), end(s), begin(s), ::tolower);
   for (auto c : string("abcdefghijklmnopqrstuvwxyz")) {
      if (s.find(c) == string::npos) {
	 cout << "NO" << endl;
	 return 0;
      }
   }
   cout << "YES" << endl;
   
   


}
