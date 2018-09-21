#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int t;
   string s;
   cin >> t;
   while (t--) {
      cin >> s;
      int l = 0, u = 0, d = 0;
      for (auto &i : s) {
	 if (islower(i)) l++;
	 else if (isupper(i)) u++;
	 else if (isdigit(i)) d++;
      }

      int A[] = { l, u, d };
      int c = count(A, A+3, 0);
      if (c == 2) {
	 int i = 0;
	 if (!l)
	    s[i++] = 'a';
	 if (!u)
	    s[i++] = 'A';
	 if (!d)
	    s[i++] = '1';	 
      } else if (c == 1) {
	 for (auto &i : s) {
	    if (!l && ((d >= u && isdigit(i)) || (u >= d && isupper(i)))) {		  
	       i = 'a'; break;
	    } else if (!u && ((d >= l && isdigit(i)) || (l >= d && islower(i)))) {
	       i = 'A'; break;
	    } else if (!d && ((u >= l && isupper(i)) || (l >= u && islower(i)))) {
	       i = '1'; break;
	    }
	 }
      }
      cout << s << endl;
   
   }
}

