#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, d;
   cin >> n >> d;

   vi A(n);
   for (auto &x : A) cin >> x;

   sort(begin(A), end(A));
   int k = 0;
   if (n == 1) d = 0;
   int i = 0, j = A.size() - 1;
   while (1) {
     if (A[j] - A[i] <= d) break;
     if (A[j] - A[j-1] >= A[i+1] - A[i])
       j++;
     else
       i++;
     k++;
   }

   cout << k << endl;
     


}


