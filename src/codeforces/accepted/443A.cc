// Problem #    : 443A
// Created on   : 2018-10-14 15:48:00
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   string s;
   getline(cin, s);
   s = s.substr(1, (int)s.size() - 2);

   stringstream ss(s);
   vector<string> A;
   
   while (getline(ss >> ws, s, ',')) {
      A.push_back(s);
   }
   sort(begin(A), end(A));
   auto i = unique(begin(A), end(A));
   cout << i - begin(A) << endl;
   


}
