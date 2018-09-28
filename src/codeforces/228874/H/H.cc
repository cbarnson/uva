#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int C[2][1005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k, x;
  cin >> n >> k >> x;

  FR(i, n) {
    int y; cin >> y;
    C[0][y]++;
  }

  for (int i = 0; i < k; i++) {
    int cnt = 0, p = i & 1;

    for (int j = 0; j <= 1000; j++) {
      for (int l = 0; l < C[p][j]; l++) {
	cout << j << " ";
      }
      cout << endl;
    }

    
    for (int j = 0; j <= 1000; j++) {
      while (C[p][j]) {
	C[p][j]--, cnt++;
	if (cnt & 1)
	  C[!p][j^x]++;
	else
	  C[!p][j]++;
      }
    }
  }
   
  int i = 0, j = n - 1, p = k & 1;
  while (!C[p][i]) i++;
  while (!C[p][j]) j--;

  cout << j << " " << i << endl;
  
}


