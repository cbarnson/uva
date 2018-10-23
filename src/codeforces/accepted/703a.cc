// Problem #    : 703a
// Created on   : 2018-10-23 09:35:48
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, a, b, s = 0;
   cin >> n;
   FR(i, n) {
      cin >> a >> b;
      
      if (a < b) s++;
      if (a > b) s--;
   }

   if (s < 0) cout << "Mishka" << endl;
   else if (s > 0) cout <<  "Chris" << endl;
   else cout << "Friendship is magic!^^" << endl;
   


}
