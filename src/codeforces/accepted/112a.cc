// Problem #    : 112a
// Created on   : 2018-09-29 10:36:43
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   string a, b;
   cin >> a >> b;

   transform(begin(a), end(a), begin(a), ::tolower);
   transform(begin(b), end(b), begin(b), ::tolower);

   int ans = 0;
   if (a < b) 
      ans = -1;
   else if (b < a)
      ans = 1;

   cout << ans << endl;
	
   


}
