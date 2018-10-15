// Problem #    : 82a
// Created on   : 2018-10-14 17:54:02
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   ll n;
   cin >> n;

   vector<string> name = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };

   n--;
   ll x = 5, y = 0;
   while (n - x >= 0) {
      n -= x; x *= 2;
      y++;
   }

   ll z = n / (1 << y);
   cout << name[z] << endl;
   
   // cout << n << " " << y << endl;
   

}
