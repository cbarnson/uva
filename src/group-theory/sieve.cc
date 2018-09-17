#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll sz;
vi primes;
bitset<10000010> p;

void sieve(ll m) {
  sz = m + 1;
  p.set();
  p[0] = p[1] = 0;
  for (ll i = 2; i <= sz; i++) {
    if (p[i]) {
      for (ll j = i * i; j <= sz; j += i) p[j] = 0;      
      primes.push_back((int)i);
    }
  }
}

bool isPrime(ll n) {
  if (n <= sz) return p[n];
  for (int i = 0; i < (int)primes.size(); i++)
    if (n % primes[i] == 0) return false;
  return true;
}

int f(int n) {
  double m = n;
  return m / (log(m) - 1);
}

int main() {

  int n = 14, m = 20;
  int n0 = n;
  cout << n << " : ";
  int i = 2;
  do {
    n = (n0 * i++) % m;
    cout << n << " ";
  } while (n != n0);
  cout << endl;
  
  // int n = 1000000;
  // sieve(n);

  // cout << primes.size() << endl;
  // cout << n << " : " << f(n) << endl;
  
  // for (int i = 0; (i * 1000) <= 10000; i++) {
  //   cout << i * 1000 << " : " << f(i * 1000) << endl;
  // }
  
  // for (int i = 0; i < 50; i++) {
  //   cout << primes[i] << endl;
  // }


}
