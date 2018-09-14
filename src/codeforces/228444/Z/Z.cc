#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   
   int n;
   string s, r = "";
   cin >> n >> s;

   for (int i = 1; i < s.length(); i++) 
      if (s[i] != s[i-1] && s[i-1] != 'D') 
	 s[i] = 'D';

   cout << ((int)s.length() - count(s.begin(), s.end(), 'D')) << endl;


}


