// Problem #    : 556a
// Created on   : 2018-10-22 09:00:24
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n; cin >> n;
   string s; cin >> s;

   cout << abs(count(begin(s), end(s), '0') - count(begin(s), end(s), '1')) << endl;
   

}
