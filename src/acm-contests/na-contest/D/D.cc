#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> ii;

vii g;
int L, W;

string dir = "UDLR";
ii dxy[] = { ii(-1,0), ii(1, 0), ii(0, -1), ii(0, 1) };
ii move(char c) {
   auto i = dir.find(c);
   assert(i != string::npos);
   return dxy[i];
}

vii next() {
   vii h(L, vi(2*W, 0));
   for (int i = 0; i < L; i++) {
      for (int j = 0; j < 2*W; j++) {
	 if (g[i][j]) {
	    int k;
	    if (i & 1) {
	       k = (j + 2*W - 1) % (2*W);
	    } else {
	       k = (j + 1) % (2*W);
	    }
	    h[i][k] = 1;
	 }
      }
   }
   return h;
}

void read() {
   g.assign(L, vi(2*W, 0));
   for (int i = 0; i < L; i++) {
      int O, I, S;
      cin >> O >> I >> S;
      vi R(2*W, 0);
      for (int j = 0; (I*j + O) < (2*W); j++) {
	 for (int k = 1; k < S; k++) {
	    int m = ((I*j + O) + k) % (2*W);
	    R[m] = 1;
	 }
      }

      // if (i & 1) {
      // 	 reverse(begin(R), end(R));
      // }
      g[i] = R;
   }
}

void print() {

   FR(i, L) {
      FR(j, 2*W) {
	 cout << g[i][j] << " ";
      }
      cout << endl;
   }
   cout << endl;
   
}


int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> L >> W;
   read();

   print();
   

}
