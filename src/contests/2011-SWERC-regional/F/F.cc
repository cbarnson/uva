#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;

int n, m, j, k;
int A[5], B[5];
string s;

int f() {
   int x;
   while (k < (int)s.length()) {
      if (islower(s[k])) {
	 k++, x = A[B[j++]];
      } else if (s[k] == '(') {
	 k++, x = f();
      } else if (s[k] == ')') {
	 k++;	 
	 return x;
      } else {
	 char op = s[k++];
	 return (op == '+' ? x + f() : (op == '-' ? x - f() : x * f()));
      }
   }
   return x;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   while (cin >> n && n) {
      REP(i, n) cin >> A[i];      
      cin >> m >> s;

      // 0, 1, ... n-1
      iota(B, B + n, 0);
      
      int g = false;
      do {
	 // init indices each time, j incr with each new variable,
	 // k with each char of the expression string
	 j = k = 0;
	 if (f() == m) {
	    g = true;
	    break;
	 }
      } while (next_permutation(B, B + n));

      cout << (g ? "YES" : "NO") << endl;
      
   }

}
