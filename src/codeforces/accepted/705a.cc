// Problem #    : 705a
// Created on   : 2018-10-14 19:31:09
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    



int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;
   
   for (int i = 1; i <= n; i++) {
      cout << "I " << (i & 1 ? "hate" : "love");
      cout << (i == n ? " it" : " that ");
   }
   cout << endl;


}
