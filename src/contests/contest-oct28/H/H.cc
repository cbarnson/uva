#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

vi A;
bool f(int x) {
   set<int> S;
   
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(0);

   int n;
   cin >> n;

   set<int> S;
   
   A.assign(n);
   for (auto &x : A) {
      cin >> x;
      int y = x;
      S.insert(y);
   }

   int m = S.size();


   int lo = 1;
   hi = lo;
   while (!f(hi)) hi *= 2;
   while (hi - lo > 5) {
      int mid = lo + (hi - lo) / 2;
      (f(mid) ? hi : lo) = mid;
   }

   while (!f(lo)) lo++;

   



}
