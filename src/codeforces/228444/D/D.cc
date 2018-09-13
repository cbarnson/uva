#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   
   ll n, m, a, b, x, y;
   cin >> n >> m >> a >> b;

   x = n % m;
   y = x * b;
   x = (m - x) * a;
   
   cout << min(x, y) << endl;


}


