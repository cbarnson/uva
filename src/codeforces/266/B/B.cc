#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);


   int n, t;
   char A[52];

   cin >> n >> t;
   REP(i, n) cin >> A[i];

   REP(j, t) {
      REP(i, n-1) {
	 if (A[i] == 'B' && A[i+1] == 'G')
	    swap(A[i], A[i+1]), i++;
      }
   }

   REP(i, n) cout << A[i];   
   cout << endl;


}


