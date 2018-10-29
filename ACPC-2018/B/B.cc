#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

vi P, H, E, D;

void rem(int p) {
   auto i = find(begin(P), end(P), p);
   // assert(*i == p);
   // cout << "player " << p << " removed from the game!" << endl;
   P.erase(i);
}

int nextPlayer(int p, int adv) {
   int idx = (int)(find(begin(P), end(P), p) - begin(P));
   ll j = ((ll)idx + (ll)adv) % (ll)P.size();
   return P[j];
}

void print() {
   FR(i, P.size()) cout << (i ? " " : "") << P[i];
   cout << endl;
}

ii nextCard(int &e, int &d) {
   int es = E.size(), ds = D.size();
   if (e < es && d < ds) {
      if (E[e] < D[d]) return ii(E[e++], 1);
      else return ii(D[d++], 0);      
   } else if (e < es) {
      return ii(E[e++], 1);
   } else if (d < ds) {
      return ii(D[d++], 0);
   }   
   return ii(-1, -1);
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(0);

   int n, e, d;
   cin >> n >> e >> d;

   P.assign(n, 0);
   iota(begin(P), end(P), 0);

   // hand
   H.assign(n, 0);

   // expl
   E.assign(e, 0);
   FR(i, e) cin >> E[i];   

   // def
   D.assign(d, 0);
   FR(i, d) cin >> D[i];

   // sort the expl and def
   sort(begin(E), end(E));
   sort(begin(D), end(D));

   e = 0, d = 0;
   int p = 0, c = 0;

   while (P.size() > 1) {
      
      ii nc = nextCard(e, d);
      if (nc.first == -1) {
	 cout << -1 << endl;
	 return 0;
      }

      int cd = nc.first;
      int xp = nc.second;

      int dx = cd - c; c = cd;
      p = nextPlayer(p, dx);

      // cout << "player " << p << " got "
      //       << (xp ? "explode" : "defuse") << endl;

      if (xp && H[p]) {
	 H[p]--;
      } else if (xp && !H[p]) {
	 // int pre = P.size();
	 int np = nextPlayer(p, 1);
	 rem(p);
	 np = nextPlayer(np, (int)P.size() - 1);
	 p = np;
	 // assert(P.size() == pre - 1);     
      } else {
	 // assert(!xp);
	 H[p] = min(5, H[p] + 1);
      }        
   }

   cout << P.front() << endl;
   
}
