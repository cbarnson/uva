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

   set<int> s;
   FR(i, n) {
     int x; cin >> x;
     if (x > 0)
       s.insert(x);
   }

   cout << s.size() << endl;
}


