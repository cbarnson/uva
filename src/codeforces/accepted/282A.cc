// Problem #    : 282A
// Created on   : 2018-09-27 23:53:10
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, j = 0;
   cin >> n;
   FR(i, n) {
      string s;
      cin >> s;
      if (s.find('+') != string::npos)
	 j++;
      else
	 j--;
   }


   cout << j << endl;
   
   


}
