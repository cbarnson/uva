#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;


int N1, N2;
vi A(1005), B(1005), C(2010);

vector<vi> dp;

bool f(int i, int j) {

   int k = i + j;
   if (k == N1 + N2) return true;

   if (dp[i][j] != -1) return dp[i][j];

   int ans = 0;
   if (i < N1 && j < N2 && A[i] == C[k] && B[j] == C[k]) {
      ans = f(i + 1, j) || f(i, j + 1);
   } else if (i < N1 && A[i] == C[k]) {
      ans = f(i + 1, j);
   } else if (j < N2 && B[j] == C[k]) {
      ans = f(i, j + 1);
   }

   dp[i][j] = ans;
   return ans;
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);


   while (cin >> N1 >> N2) {
      if (!N1 && !N2) break;

      dp.assign(1005, vi(1005, -1));
      FR(i, N1) cin >> A[i];
      FR(j, N2) cin >> B[j];
      FR(k, N1 + N2) cin >> C[k];
      
      if (!f(0, 0)) cout << "not ";
      cout << "possible" << endl;
   }
   

}
