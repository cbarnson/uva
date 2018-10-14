// Problem #    : 236A
// Created on   : 2018-10-14 09:32:50
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

   sort(begin(s), end(s));
   auto i = unique(begin(s), end(s));
   int c = i - begin(s);

   if (c & 1) cout << "IGNORE HIM!" << endl;
   else cout << "CHAT WITH HER!" << endl;
   


}
