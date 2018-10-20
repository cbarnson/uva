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

   // 0.5 < r < 2, log(r) can be negative, use large neg inf 
   map<string, double> MP = { { "pink", log(1.0) }, { "blue", 0x3f3f3f3f * -1.0 } };
   
   FR(i, n) {

     string u, v; cin >> u >> v;
     double r; cin >> r;
     
     // add if either not seen before
     for (auto s : {u, v}) {
       if (MP.find(s) == MP.end())
	 MP.insert({s, 0x3f3f3f3f * -1.0 });
     }
     MP[u] = max(MP[u], MP[v] + log(r));
   }

   cout << setprecision(6) << fixed << min(10.0, exp(MP["blue"])) << endl;
   
}
   
