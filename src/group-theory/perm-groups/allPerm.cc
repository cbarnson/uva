#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> A(n);
  iota(begin(A), end(A), 1);


  int i = 1;
  do {
    cout << setw(3) << i++ << " : ";
    for (auto &x : A) cout << setw(4) << x;
    cout << endl;
    
  } while (next_permutation(begin(A), end(A)));
}
