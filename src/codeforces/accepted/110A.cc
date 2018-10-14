// Problem #    : 110A
// Created on   : 2018-10-14 11:05:06
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
   cin >> s;

   int cnt = count_if(begin(s), end(s), [](char c) { return c == '4' || c == '7'; });
   if (cnt == 4 || cnt == 7)
      cout << "YES" << endl;
   else
      cout << "NO" << endl;

   
   


}
