#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i) 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   string S;
   cin >> S;

   string last = S;
   for (int i = (int)S.length() / 2; i > 0; i--) {

      string A = string(S.rbegin(), S.rbegin() + i);
      string B = string(S.rbegin() + i, S.rbegin() + 2 * i); reverse(B.begin(), B.end());
      string C = string(S.rbegin() + 2 * i, S.rend()); reverse(C.begin(), C.end());
      
      for (int i = 0; i < A.length(); i++) {
	 if (A[i] < B[i])
	    B[i] = A[i];
      }

      if (string(C + B) < last)
	 last = string(C + B);
   }
   cout << last << endl;

   

}
