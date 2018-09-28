#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;

   vi A(n);
   for (auto &x : A) cin >> x;

   sort(begin(A), end(A));
   for (int i = 1; i < A.size() - 1; i += 2) {
      if (A[i] >= A[i - 1] && A[i] >= A[i+1])   continue;

      swap(A[i], A[i+1]);
      if (A[i] >= A[i - 1] && A[i] >= A[i+1])
	 continue;
      else {
	 cout << "impossible" << endl;
	 return 0;
      }
   }
   for (int i = 0; i < A.size(); i++) {
      if (i) cout << " ";
      cout << A[i];
   }
   cout << endl;

   
}
