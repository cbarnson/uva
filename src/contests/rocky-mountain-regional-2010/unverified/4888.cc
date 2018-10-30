// Cody Barnson
// 4888 - railroad
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int NN = 1000;

int A[NN];
int B[NN];
int C[2*NN];
int na, nb;

int main() {

   while (cin >> na >> nb && na != 0 && nb != 0) {

      for (int i = na-1; i >= 0; i--) 
	 cin >> A[i];
      for (int i = nb-1; i >= 0; i--) 
	 cin >> B[i];
      for (int i = (na+nb)-1; i >= 0; i--) 
	 cin >> C[i];

      vector<ii> v;
      
      bool possible = true;
      int a = 0, b = 0;
      while ((a+b) < (na+nb)) {

	 if (a < na && b < nb) { // A and B both have values left
	    if (C[a+b] == A[a] && C[a+b] == B[b]) { // tie, both A and B match

	       // count A matches
	       int aa = a+1;
	       while (aa < na && C[aa+b] == A[aa]) 
		  aa++;
	       
	       // count B matches
	       int bb = b+1;
	       while (bb < nb && C[a+bb] == B[bb]) 
		  bb++;
	       
	       // take better, update index
	       if ((aa - a) < (bb - b)) {
		  v.push_back(ii(1, B[b]));
		  b++;
	       } else {
		  v.push_back(ii(0, A[a]));
		  a++;
	       }	       
	    } else if (C[a+b] == A[a]) { // matches A
	       v.push_back(ii(0, A[a]));
	       a++;
	    } else if (C[a+b] == B[b]) { // matches B
	       v.push_back(ii(1, B[b]));
	       b++;
	    } else { // neither matches, not possible
	       possible = false;
	       break;
	    }
	    
	 } else if (a < na && b == nb) { // A only has values left
	    if (C[a+b] == A[a]) {
	       v.push_back(ii(0, A[a]));
	       a++;
	    } else { // failed to match
	       possible = false;
	       break;
	    }
	 } else if (b < nb && a == na) { // B only has values left
	    if (C[a+b] == B[b]) {
	       v.push_back(ii(1, B[b]));
	       b++;
	    } else { // failed to match
	       possible = false;
	       break;
	    }
	 }


	 for (int i = 0; i < v.size(); i++) {
	    cout << "(";
	    if (v[i].first) cout << "B,";
	    else cout << "A,";
	    cout << v[i].second << ") ";
	 }
	 cout << endl;	 
      }

    
      if (possible)
	 cout << "possible" << endl;
      else
	 cout << "not possible" << endl;

      
   }


   return 0;
}
