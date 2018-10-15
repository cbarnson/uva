// Problem #    : 734A
// Created on   : 2018-10-14 15:02:57
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, a = 0, d = 0;   
   char c;

   cin >> n;
   
   FR(i, n) {
      cin >> c;
      (c == 'A' ? a : d) += 1;
   }

   cout << (a < d ? "Danik" : (a == d ? "Friendship" : "Anton")) << endl;
   


}
