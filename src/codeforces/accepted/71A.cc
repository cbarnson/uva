// Problem #    : 71A
// Created on   : 2018-09-27 21:15:34
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
   cin >> n;

   FR(i, n) {
      string s;
      cin >> s;
      int l = s.length();
      if (l > 10) {
	 cout << s[0] << l - 2 << s[l - 1] << endl;
      } else
	 cout << s << endl;
   }

   
   


}
