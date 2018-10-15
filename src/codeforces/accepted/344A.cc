// Problem #    : 344A
// Created on   : 2018-10-14 14:39:41
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   string a = "", b;
   int n;
   cin >> n;
   FR(i, n) {
      cin >> b;
      a += b;
   }

   int cnt = 1;
   for (int i = 1; i < a.size(); i++) {
      if (a[i] == a[i-1]) cnt++;
   }
   cout << cnt << endl;


}
