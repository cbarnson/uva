#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;

const int MM = 1000001;

int P[MM * 2];

// Different approach that just tracks 2 mins, also TLE...
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int n;
   while (cin >> n && n) {

      
      for (int i = 0; i < n; i++) {
	 cin >> P[i];
	 P[i + n] = P[i];
	 if (i) P[i] += P[i - 1];	 
      }

      // process other half of partial sum array
      for (int i = 0; i < n; i++) {
	 P[i + n] = P[i + n] + P[i + n - 1];
      }
      
      int m1, m2;
      // find mins
      for (int i = 0; i < n; i++) {
	 if (!i) {
	    m1 = 0, m2 = 0;
	 } else {	    
     	    if (P[i] < P[m1]) {
               // m1 >= m2, always
	       m2 = m1;
	       m1 = i;
	    }
	 }
      }
            
      int cnt = 0;
      for (int i = 0; i < n; i++) {
	 if (!i && (P[m1] < 0 || P[m2] < 0)) {
	    cnt++; continue;
	 }

	 int nw = P[i + n - 1] - P[i - 1];

	 if (nw < (P[m1 + i] - P[i - 1])) {
	    m2 = m1;
	    m1 = i;
	 }

	 if ((P[m1 + i] - P[i - 1]) < 0 || (P[m2 + i] - P[i - 1]) < 0) {
	    cnt++;
	 }
      }

      cout << n - cnt << endl;
   }
}
