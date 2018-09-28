#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

<<<<<<< HEAD
int C[2][1005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k, x;
  cin >> n >> k >> x;

  FR(i, n) {
    int y; cin >> y;
    C[0][y]++;
  }

  for (int i = 0; i < k; i++) {
    int cnt = 0, p = i & 1;

    for (int j = 0; j <= 1000; j++) {
      for (int l = 0; l < C[p][j]; l++) {
	cout << j << " ";
      }
      cout << endl;
    }

    
    for (int j = 0; j <= 1000; j++) {
      while (C[p][j]) {
	C[p][j]--, cnt++;
	if (cnt & 1)
	  C[!p][j^x]++;
	else
	  C[!p][j]++;
      }
    }
  }
   
  int i = 0, j = n - 1, p = k & 1;
  while (!C[p][i]) i++;
  while (!C[p][j]) j--;

  cout << j << " " << i << endl;
  
=======
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
>>>>>>> 88269f1da44e962338a0ebca227e32f727c45fb6
}


