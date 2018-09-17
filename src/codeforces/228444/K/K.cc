#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   
  int n;
  int a[51] = {};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  auto e = unique(a, a+n);
  cout << distance(a, e) << endl;


}


