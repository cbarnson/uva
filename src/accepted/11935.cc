// Problem: 11935 Through the Desert
// Status : Accepted
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9
#define bitcount __builtin_popcount
#define GCD __gcd

typedef pair<int, int> pii;
typedef vector<pii> vii;

int multBy2(int num) { return num << 1; }
int divBy2(int num) { return num >> 1; }
int numberOfDigits(int num) { return floor(log10(num)) + 1; }
bool isOdd(int num) { return (num & 1); }
bool isPowerOf2(int x) { return x && (!(x & (x - 1))); }; // for positive integers
void printBinaryRep(int x) { cout << bitset<32>(x).to_string() << endl; }

const double PI = acos(-1.0);
const double E = exp(1.0);

vector< pair<int, string> > path;
vector<int> FC;
int n;

bool can(double f) {

   double fuel = f;
   double fc = (double)FC[0] / 100.0;
   double leak = 0.0;
   
   int last = 0;
   int len = path.size();
   for (int i = 1; i < len; i++) {

      // update
      int dist = abs(path[i].first - last);
      fuel = fuel - (fc * dist) - (leak * dist);
      if (fuel < 0.0) 
	 return false;
      
      if (path[i].second == "Gas station") {
	 fuel = f;
      } else if (path[i].second == "Mechanic") {
	 leak = 0.0;
      } else if (path[i].second == "Fuel consumption") {
	 fc = (double)FC[i] / 100.0;
      } else if (path[i].second == "Leak") {
	 leak = leak + 1.0;
      }
      last = path[i].first;
   }


   // success
   return true;
}

void print(int d, string s, int n) {
   cout << d << ' ' << s << ' ' << n << endl;
}

void input(string &s) {
   if (s == "Fuel" || s == "Gas") {
      string s2;
      cin >> s2;
      s += " " + s2;
   }
}

int main() {

   int d;
   string s;
   while (cin >> d >> s) {
      input(s);
      cin >> n;
      if (d == 0 && s == "Fuel consumption" && n == 0) {
	 break;
      }

      

      path.clear();
      FC.clear();

      path.pb({d, s});
      FC.pb(n);
      
      do {
	 cin >> d >> s;
	 input(s);
	 if (s == "Fuel consumption")
	    cin >> n;
	 FC.pb(n);
	 path.pb({d, s});	 
      } while(s != "Goal");
      FC.pb(n);
      path.pb({d, s});
      
      

      double lo = 0.0, hi = 10000.0, mid = 0.0, ans = 0.0;
      while (fabs(hi - lo) > EPS) {
	 mid = (hi + lo) / 2.0;
	 if (can(mid)) {
	    ans = mid;
	    hi = mid;
	 } else {
	    lo = mid;
	 }
      }

      printf("%.3lf\n", ans);
      



   }


   
   return 0;
}
