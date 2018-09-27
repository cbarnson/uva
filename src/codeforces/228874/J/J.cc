#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, a, b;
   cin >> n >> a >> b;

   queue<ii> q;
   for (int i = 1; i <= n; i++)
     q.push(ii(i, 1));

   int m = 31 - __builtin_clz(n);
   
   while (!q.empty()) {
     ii u = q.front(); q.pop(); ii v = q.front(); q.pop();
     
     if ((u.first == a && v.first == b) || (u.first == b && v.first == a)) {
       if (u.second == m)
	 cout << "Final!" << endl;
       else
	 cout << u.second << endl;
       return 0;
     }

     if (u.first == a || u.first == b)
       q.push(ii(u.first, u.second + 1));
     else
       q.push(ii(v.first, v.second + 1));
       
   }

}


