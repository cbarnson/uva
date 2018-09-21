#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, k, m;
   cin >> n >> k >> m;

   vector<string> W(n);
   FR(i, n) cin >> W[i];

   vi C(n);
   FR(i, n) cin >> C[i];

   map<string, int> m_wg;
   vi BC(n, -1);
   
   FR(g, k) {
      int x, y; cin >> x;
      while (x--) {
	 cin >> y; y--;
	 m_wg.insert(make_pair(W[y], g));
	 if (BC[g] == -1 || BC[g] > C[y]) BC[g] = C[y];
      }
   }

   string s;
   ll t = 0;
   FR(i, m) {
      cin >> s;
      t += BC[m_wg[s]];
   }

   cout << t << endl;

}


