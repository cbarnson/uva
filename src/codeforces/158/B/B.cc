#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int A[100005];

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int n, m = 4;
   cin >> n;
   REP(i, n) cin >> A[i];

   sort(A, A+n);
   int i = 0, j = n - 1, k = 0;
   while (j >= i) {
      if (i == j) {
	 k++; break;
      }

      while (A[i] + A[j] <= m && j > i) {
	 A[j] += A[i++];
      }
      k++, j--;
   }

   cout << k << endl;

}


