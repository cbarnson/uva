#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;

   vector<ii> S(n);
   int w;
   FR(i, n) {
      cin >> w;
      S[i] = ii(w, i+1);
   }

   sort(begin(S), end(S));
   queue<ii> A;
   FR(i, n) A.push(S[i]);
   stack<ii> B;

   for (int i = 0; i < 2*n; i++) {
      char c;
      cin >> c;
      if (c == '0') {
	 ii a = A.front(); A.pop();
	 cout << a.second << " ";
	 B.push(a);
      } else {
	 ii b = B.top(); B.pop();
	 cout << b.second << (i == (2*n) - 1 ? "" : " ");	 
      }
   }
   cout << endl;



}
