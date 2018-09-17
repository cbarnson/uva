#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;

int n, b;

vector<int> A;

bool f(int x) {
  int y = b - n;

  REP(i, n) {
    int c = 1;
    while (x < ((A[i] + c - 1) / c)) {
      if (!y) return false;
      y--; c++;
    }
  }
  return true;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   while (cin >> n >> b) {
     if (n == -1 && b == -1) return 0;

     A.assign(n, 0);
     REP(i, n) {
       cin >> A[i];
     }

     int lo = 1, hi = 1;
     while (!f(hi)) hi *= 2;
     while (hi - lo > 5) {
       int mid = lo + (hi - lo) / 2;
       (f(mid) ? hi : lo) = mid;
     }
     while (!f(lo)) lo++;

     cout << lo << endl;
   }

}
