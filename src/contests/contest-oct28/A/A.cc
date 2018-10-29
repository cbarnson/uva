#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;


bool leapyear(int y) {
   return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}
   

int getm(vi &P) {
   FR(i, 3) {
      if (P[i] == 1) {
	 return i;
      }
   }
}

int gety(vi &P) {
   FR(i, 3) {
      if (P[i] == 2) {
	 return i;
      }
   }
}

int getd(vi &P) {
   FR(i, 3) {
      if (P[i] == 0) {
	 return i;
      }
   }
}


vi M = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

vector<vi> f(vector<string> &A) {

   vector<vi> B;
   FR(i, A.size()) {
      stringstream ss(A[i]);
      string a, b, c;
      getline(ss, a, '/');
      getline(ss, b, '/');
      ss >> c;

      // cout << a << " " << b << " " << c << endl;

      int x = stoi(a), y = stoi(b), z = stoi(c);
      // cout << x << " " << y << " " << z << endl;
      B.push_back({x, y, z});
   }
   return B;
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(0);

   int n;
   cin >> n;

   vector<string> A;
   FR(i, n) {
      string a;
      cin >> a;
      A.push_back(a);
   }
      
   auto B = f(A);
   // for (auto &x : B) {
   //    for (auto &y : x) {
   // 	 cout << " " << y;
   //    }
   //    cout << endl;
   // }


   vi P(3);
   iota(begin(P), end(P), 0);
   sort(begin(P), end(P));

   int ans = -1;
   vi S;
   
   do {

      bool valid = true;

      // for each given date
      for (int i = 0; i < B.size(); i++) {

	 // for each field, 3 total
	 int d, m, y;
	 for (int j = 0; j < B[i].size(); j++) {	    
	    if (P[j] == 0) d = B[i][j];
	    else if (P[j] == 1) m = B[i][j];
	    else y = B[i][j];
	 }

	 if (m < 1 || m > 12 || d < 1) {
	    valid = false;
	    goto hell;
	 }

	 int exp_d = M[m] + (leapyear(y + 2000) ? 1 : 0);
	 if (d > exp_d) {
	    valid = false;
	    goto hell;
	 }
	 
	 
      }

      if (valid) {

	 if (ans == -1) {
	    ans = 1;
	    S = P;
	 } else {
	    // already had ans, so now unsure
	    cout << "UNSURE" << endl;
	    return 0;
	 }
	 
      }
     hell:
      ;
   } while (next_permutation(begin(P), end(P)));

   if (ans == -1) {
      // nothing was valid, impossible
      cout << "IMPOSSIBLE" << endl;
      return 0;
   }

   // have ans encoded in S
   FR(i, 3) {
      cout << (i ? "/" : "");
      if (S[i] == 0) {
	 cout << "DD";
      } else if (S[i] == 1) {
	 cout << "MM";
      } else {
	 cout << "YY";
      }      
   }
   cout << endl;
   


}
