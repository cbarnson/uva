#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;



int main() {

   int n;
   
   while (cin >> n) {
   
      int x = (1 << n) - 1 - n;
      cout << x << endl;

   }
   
   return 0;
}