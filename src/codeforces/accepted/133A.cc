// Problem #    : 133A
// Created on   : 2018-10-14 09:58:00
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   string s = "HQ9";
   char c;
   while (cin >> c) {
      if (s.find(c) != string::npos) {
	 cout << "YES" << endl;
	 return 0;
      }
   }
   cout << "NO" << endl;
   


}
