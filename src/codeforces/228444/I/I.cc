#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   

   int a[1001] = {};
   int n;
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }

   sort(a, a+n);
   int x = (n - 1) / 2;
   cout << a[x] << endl;

}


