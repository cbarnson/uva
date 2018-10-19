#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {

  int n;
  cin >> n;

  vector<int> ans;
  
  for (int i = 0; i < n; i++) {
    ans.push_back(i);
  }

  cout << "Z_" << n << " = {";
  for (auto &x : ans) {
    cout << " " << x;
  }
  cout << " }" << endl;

  for (auto &x : ans) {
    vector<int> gen;
    int y = x;
    do {
      gen.push_back(y);
      y = (y + x) % n;
    } while (y != x);
    
    cout << "<" << x << "> = {";
    for (auto &j : gen) {
      cout << " " << j;
    }
    cout << " }" << endl;
  }


}