// Problem #    : h
// Created on   : 2018-10-20 15:43:50
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    


int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n; cin >> n;

   vector<string> A(n);
   int cnt = 0;
   FR(i, n) { cin >> A[i]; cnt += count(begin(A[i]), end(A[i]), '.'); }   

   if (cnt > (n * n) / 4) {
      cout << "invalid grille" << endl;
      return 0;
   }
   
   auto r = [&](vector<string> &B) {
      vector<string> C = B;
      for (int i = 0; i < n; i++) {
	 for (int j = 0; j < n; j++) {
	    C[j][n - i - 1] = B[i][j];
	 }
      }
      B = C;
   };

   string s;
   cin >> s;

   
   
   
   int m = 0;
   vector<string> D(n, string(n, '.'));
   
   FR(k, 4) {
      if (k) r(A);

      FR(i, n) {
	 FR(j, n) {
	    if (A[i][j] == '.') {
	       D[i][j] = s[m++];
	    }
	 }
      }
   }

   string ans = "";
   FR(i, n) FR(j, n) ans += D[i][j];

   if (ans.find(".") == string::npos)   
      cout << ans << endl;
   else
      cout << "invalid grille" << endl;
   


}
