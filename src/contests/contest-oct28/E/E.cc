#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(0);

   int n;
   cin >> n;

   vector<pair<ii, string> > A;
   FR(i, n) {
      string s;
      int a, b, c;
      cin >> s >> a >> b >> c;
      A.push_back(make_pair(ii(a + b + c, a), s));
   }

   sort(begin(A), end(A));
   cout << A.front().second << endl;
      
      



}
