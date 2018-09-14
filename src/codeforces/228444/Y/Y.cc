#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int toMin(ii hm) {
   return hm.first * 60 + hm.second;
}

ii toHM(int m) {
   return ii(m / 60, m % 60);
}

int main() {
   
   int hh, mm, H, D, C, N;
   double tc, tcd;
   cin >> hh >> mm >> H >> D >> C >> N;

   tc = C * ((H / N) + (H % N ? 1 : 0));

   int H2 = H + (D * (max(0, toMin(ii(20, 0)) - toMin(ii(hh, mm)))));
   tcd = (double)C * 0.8 * (double)((H2 / N) + (H2 % N ? 1 : 0));

   cout << setprecision(4) << fixed << min(tc, tcd) << endl;

}


