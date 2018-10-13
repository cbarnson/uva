#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;

typedef vector<double> vd;

vd minL = { 125, 90, 0.25 };
vd maxL = { 290, 155, 7 };
vd maxPk = { 380, 300, 50 };

double l, h, t;
double s = 0;
bool islet() {

   vd A = { l, h, t };
   FR(i, 3) {
      if (minL[i] > A[i])
   	 return false;
   }

   FR(i, 3) {
      if (maxL[i] < A[i])
	 return false;
   }
   return true;
}

bool ismail() {
   vd A = { l, h, t };
   FR(i, 3) {
      if (minL[i] > A[i]) {
	 return false;
      }
   }
   if ((2*h + 2*t + l) > 2100) return false;
   return true;
}

bool isparc() {
   vd A = { l, h, t };
   FR(i, 3) {
      if (A[i] > maxPk[i])
	 return true;
   }
   return false;
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   while (cin >> l >> h >> t) {
      if (l == 0 && h == 0 && t == 0) break;

      s = l + h + t;
      vd A = { l, h, t };
      sort(begin(A), end(A));
      l = A[2], h = A[1], t = A[0];
      
      // is let
      if (!ismail()) {
	 cout << "not mailable" << endl;
      } else if (islet()) {
	 cout << "letter" << endl;
      } else if (isparc()) {
	 cout << "parcel" << endl;
      } else {
	 cout << "packet" << endl;
      }
      
   }

}
