// Problem #    : t
// Created on   : 2018-10-28 09:37:39
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   string s;
   cin >> s;

   int n = s.size();

   vi ans(n, 0);

   char c[] = { 'a', 'b' };
   int j = 0;
   for (int i = n - 1; i >= 0; i--) {
      if (s[i] == c[j])
	 ans[i] = 1, j = !j;
   }

   FR(i, n) {
      cout << (i ? " " : "") << ans[i];
   }
   cout << endl;
   
   
   
}
