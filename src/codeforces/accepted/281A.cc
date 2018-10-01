// Problem #    : 281A
// Created on   : 2018-10-01 14:04:58
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

   transform(begin(s), begin(s) + 1, begin(s), ::toupper);
   cout << s << endl;


}
