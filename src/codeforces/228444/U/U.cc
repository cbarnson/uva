#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   
   int n, m, x;
   int A[1001] = {};

   cin >> n >> m;
   for (int i = 0; i < m; i++) {
      cin >> x; A[x]++;
   }

   cout << *min_element(A+1, A+n+1) << endl;

}


