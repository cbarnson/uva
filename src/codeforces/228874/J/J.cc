#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

bool pt(int i) {
  return i && (!(i & (i - 1)));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 1; i <= 256; i++) {

    int x = i;
    if (x == 1 || !pt(x)) {
      x = 31 - __builtin_clz(x << 1);
    } else {
      x = 31 - __builtin_clz(x);
    }
    cout << i << setw(4) << x << setw(4) << (1 << x) << endl;
  }
  return 0;
   
  int n, a, b;
  cin >> n >> a >> b;

  // ----

  


  // ----

  
  int d = abs(a - b);
  int s = 31 - __builtin_clz(d) + 1;

  if (s == 31 - __builtin_clz(n))
    cout << "Final!" << endl;
  else
    cout << s << endl;
}


