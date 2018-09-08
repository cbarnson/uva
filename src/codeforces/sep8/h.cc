#include <bits/stdc++.h>
using namespace std;

string key = "XMSL";
int A[5][4];
int B[5][4];

int main() {

   int n;
   string s;
   while (cin >> n) {

      for (int i = 0; i < 5; i++) {
	 fill(A[i], A[i]+4, 0);
	 fill(B[i], B[i]+4, 0);
      }
      
      for (int i = 0; i < n * 2; i++) {
	 cin >> s;
	 int len = (int)s.length();
	 for (int j = 0; j < (int)key.size(); j++) {
	    int cnt = count(s.begin(), s.end(), key[j]);
	    if (i < n) 
	       A[len][j] += cnt;
	    else
	       B[len][j] += cnt;	       
	 }
      }

      // ans
      int t = 0;
      for (int i = 1; i < 5; i++) {
	 int lt = 0;
	 for (int j = 0; j < 4; j++) {
	    lt += abs(A[i][j] - B[i][j]);
	 }
	 t += (lt / 2);	 
      }
      cout << t << endl;

      
      
   }


}
