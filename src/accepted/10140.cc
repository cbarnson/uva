// UVa 10140 - Prime Distance
// Cody Barnson
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll size;
vector<int> vec_primes;
bitset<10000010> primes; // value may need to be tweaked in rare cases

// Sieve of Eratosthenes
void sieve(ll m) {
   size = m + 1;
   primes.set();
   primes[0] = primes[1] = 0;
   for (ll i = 2; i <= size; i++) {
      if (primes[i]) {
	 for (ll j = i * i; j <= size; j += i) {
	    primes[j] = 0;
	 }
	 vec_primes.push_back((int)i);
      }
   }
}

// Optimized primality test
bool isPrime(ll x) {
   if (x <= size) {
      return primes[x];
   }
   for (int i = 0; i < (int)vec_primes.size(); i++) {
      if (x % vec_primes[i] == 0) {
	 return false;
      }      
   }
   return true;
}

int main() {

   // Run Sieve of Eratosthenes up to divisors <= sqrt(N), to find all primes up to N
   ll m = sqrt(INT_MAX);
   sieve(m);

   ll lo, hi;
   while (cin >> lo >> hi) {

      // Use optimized prime testing function on each element in the considered range
      vector<int> adj;
      for (ll i = lo; i <= hi; i++) {
	 if (isPrime(i)) {
	    adj.push_back((int)i);
	 }
      }

      // Condition for adjacent primes
      if (adj.size() > 1) {
	 int min1, min2, max1, max2;
	 int mmin = INT_MAX, mmax = -1;
	 // iterate over all primes in range [L..U], find closest and most distant adjacent primes
	 for (int i = 1; i < (int)adj.size(); i++) {
	    int diff = adj[i] - adj[i-1];
	    if (diff < mmin) {
	       // update min
	       mmin = diff;
	       min1 = adj[i-1];
	       min2 = adj[i];
	    }
	    if (diff > mmax) {
	       // update max
	       mmax = diff;
	       max1 = adj[i-1];
	       max2 = adj[i];	       
	    }
	 }
	 cout << min1 << "," << min2 << " are closest, " << max1 << "," << max2 << " are most distant." << endl;
      } else {
	 cout << "There are no adjacent primes." << endl;
      }
   }
   
   return 0;
}
