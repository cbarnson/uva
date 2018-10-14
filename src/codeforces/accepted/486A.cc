// Problem #    : 486A
// Created on   : 2018-10-14 12:19:48
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   
   ll n, a;
   cin >> n;

   a = ((n + 1) / 2) * (n & 1 ? -1LL : 1LL);
   cout << a << endl;


}
