#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

vi P, H, E, D;

void rem(ll p) {
   auto i = find(begin(P), end(P), p);
   // assert(*i == p);
   // cout << "player " << p << " removed from the game!" << endl;
   P.erase(i);
}

ll nextPlayer(ll p, ll adv) {
   ll idx = (ll)(find(begin(P), end(P), p) - begin(P));
   ll j = ((ll)idx + (ll)adv) % (ll)P.size();
   return P[j];
}

void print() {
   FR(i, P.size()) cout << (i ? " " : "") << P[i];
   cout << endl;
}

ii nextCard(ll &e, ll &d) {
   ll es = E.size(), ds = D.size();
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

   ll n, e, d;
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

   e = 0, d = 0;
   ll p = 0, c = 0;

   while (P.size() > 1) {
      
      ii nc = nextCard(e, d);
      if (nc.first == -1) {
	 cout << -1 << endl;
	 return 0;
      }

      ll cd = nc.first;
      ll xp = nc.second;

      ll dx = cd - c; c = cd;
      p = nextPlayer(p, dx);

      // cout << "player " << p << " got "
      // 	   << (xp ? "explode" : "defuse") << endl;

      if (xp && H[p]) {
	 H[p]--;
      } else if (xp && !H[p]) {
	 // int pre = P.size();
	 ll np = nextPlayer(p, 1);
	 rem(p);
	 np = nextPlayer(np, (ll)P.size() - 1);
	 p = np;
	 // assert(P.size() == pre - 1);	 
      } else {
	 // assert(!xp);
	 H[p] = min(5, H[p] + 1);
      }	       
   }

   cout << P.front() << endl;
   
}
