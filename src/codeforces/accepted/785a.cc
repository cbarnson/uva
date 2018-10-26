// Problem #    : 785a
// Created on   : 2018-10-26 15:35:15
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   string s[] = { "Icosahedron", "Dodecahedron", "Octahedron", "Tetrahedron", "Cube" };
   int a[] = { 20, 12, 8, 4, 6 };

   int n;
   string x;
   cin >> n;
   int ans = 0;
   FR(i, n) {
      cin >> x;
      int j = find(s, s+5, x) - s;
      ans += a[j];
   }
   cout << ans << endl;
   


}
