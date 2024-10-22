#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int A[105];
int B[105];

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> A[i];
      B[A[i]]++;
   }

   int ones = count(B, B+101, 1);
   if (ones & 1) {

      int k = count_if(B, B+101, [](int x) { return x > 2; });
      if (!k) {
	 cout << "NO" << endl;
	 return 0;
      }
      
      int j = (ones - 1) / 2;
      k = 1;
      cout << "YES" << endl;
      for (int i = 0; i < n; i++) {
	 if (B[A[i]] == 1 && j > 0) {
	    cout << "B"; j--;
	 } else if (B[A[i]] > 2 && k > 0) {
	    cout << "B"; k--;
	 } else {
	    cout << "A";
	 }
      }
      
   } else {
      cout << "YES" << endl;
      int j = ones / 2;
      for (int i = 0; i < n; i++) {
	 if (B[A[i]] == 1 && j > 0) {
	    cout << "B"; j--;
	 } else {
	    cout << "A";
	 }
      }
   }
   cout << endl;

}


