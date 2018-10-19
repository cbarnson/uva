// Problem #    : 4c
// Created on   : 2018-10-18 17:34:12
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   map<string, int> mp;

   int n;
   cin >> n;
   FR(i, n) {

      string s;
      cin >> s;

      if (mp.find(s) != mp.end()) {
	 cout << s << mp[s]++ << endl;
      } else {
	 mp.emplace(s, 1);
	 cout << "OK" << endl;
      }
      
   }
   


}
