// Cody Barnson
// 10026 - shoemaker's problem
#include <bits/stdc++.h>
using namespace std;

// swap index i with index j
void swap(int id[1000], int i, int j) {
   int temp = id[i];
   id[i] = id[j];
   id[j] = temp;
}

void swap(double arr[1000], int i, int j) {
   double temp = arr[i];
   arr[i] = arr[j];
   arr[j] = temp;
}

int main() {

   int tt;
   cin >> tt;
   while (tt--) {
      int n;
      cin >> n;
      int id[1000];   // 0-based, fix when printout
      double t[1000]; // time to finish the job
      double s[1000]; // per day late penalty

      // get input
      for (int i = 0; i < n; i++) {
	 id[i] = i;
	 cin >> t[i] >> s[i];
      }

      // bubble sort, tiebreak with lexicographical by id
      for (int i = 0; i < (n-1); i++) {
	 for (int j = 0; j < (n-i-1); j++) {
	    // swap condition is by lower tj/sj ratio
	    double x = t[j] / s[j];
	    double y = t[j+1] / s[j+1];
	    // j+1 < j
	    if (y < x) { 
	       swap(id, j, j+1);
	       swap(t, j, j+1);
	       swap(s, j, j+1);
	    } else if (x == y) {
	       // tiebreaker, swap if ahead has the lower id
	       if (id[j+1] < id[j]) {
		  swap(id, j, j+1);
		  swap(t, j, j+1);
		  swap(s, j, j+1);	       
	       }
	    }	    
	 }
      }
      // solution, job order by id
      for (int i = 0; i < n; i++) {
	 if (i) cout << " ";
	 cout << id[i]+1;
      }
      cout << endl;
      // line between consecutive cases
      if (tt) cout << endl;
   }
   return 0;
}
