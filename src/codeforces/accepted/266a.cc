// Problem #    : 266a
// Created on   : 2018-09-29 10:48:30
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
   string s;
   cin >> n >> s;

   int cnt = 0;
   for (int i = 1; i < s.length(); i++)
      if (s[i] == s[i-1]) cnt++;

   cout << cnt << endl;

}
