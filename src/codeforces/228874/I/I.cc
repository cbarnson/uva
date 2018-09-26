#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int a, b;
   cin >> a >> b;

   int d = abs(a - b);
   int o = 0;
   if (d & 1) o = 1, d--;

   int n = d / 2;
   int s = n * (n + 1) + (o ? n + 1 : 0);

   cout << s << endl;

}


