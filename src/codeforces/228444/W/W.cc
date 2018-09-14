#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   
   int n, m;
   cin >> n >> m;
   vector<string> A(n);

   for (auto &x : A) cin >> x;
   sort(A.begin(), A.end());
   auto e = unique(A.begin(), A.end());
   vi seen(m, 0);
   for (auto i = A.begin(); i != e; ++i) {
      for (int j = 0; j < m; j++) {
	 if ((*i)[j] == '#') {
	    if (!seen[j])
	       seen[j] = true;
	    else {
	       cout << "No" << endl;
	       return 0;
	    }
	 }
      }
   }

   cout << "Yes" << endl;

}


