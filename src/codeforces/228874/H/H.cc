#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MXC = 1025;
int C[2][1025];

int main() {

   // FR(i, 2) FR(j, 1025) C[i][j] = 0;
   int n, k, x;
   scanf("%d %d %d ", &n, &k, &x);

   FR(i, n) {
      int s;
      scanf(" %d", &s);
      C[0][s]++;
   }

   int last = 0;
   FR(i, k) {
      int p = i & 1, cnt = 0;
      last = i;
      for (int j = 0; j < MXC; j++) {
	 if (C[p][j]) {
	    for (int m = 0; m < C[p][j]; m++) {
	       cnt++;
	       int l = (cnt & 1 ? (j ^ x) : j);
	       C[!p][l]++;	       
	    }
	    C[p][j] = 0;
	 }
      }
   }

   int lo = -1, hi = -1, p = last & 1;
   if (k == 0) {
      p = 1;
   }
   FR(i, MXC) {
      if (C[!p][i] > 0) {
   	 lo = (lo == -1 ? i : lo);
   	 hi = i;	 
      }
   }
   printf("%d %d\n", hi, lo);
}


