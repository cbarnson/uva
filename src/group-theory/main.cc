#include <bits/stdc++.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))

using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
  return a * (b / gcd(a, b));
}

int main() {

  int m = 4;

  vector<int> A = { 0, 1, 2, 3 };
  int n = A.size();
  vector< vector<int> > C;
  C.assign(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      C[i][j] = (A[i] * A[j]) % m;
    }
  }

  for (int i = 0; i < n; i++) {
    if (!i) {
      cout << "% " << setw(3) << m << setw(2) << "| ";
      for (int j = 0; j < n; j++) {
	cout << setw(4) << A[j];
      }
      cout << endl << "-------";
      for (int j = 0; j < n; j++)
	cout << setw(4) << "----";
      cout << endl;
    }
    cout << setw(4) << A[i] << " | ";
    for (int j = 0; j < n; j++) {
      cout << setw(4) << C[i][j];
    }
    cout << endl;
  }
  cout << endl;

}
