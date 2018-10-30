#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const double E = exp(1.0);
const double EPS = 0.00000001;

const double LIM = 1 / E;

double fac(double n) {
   if (n < 2) return 1;
   return n * fac(n - 1);
}

double derange(int n) {
   double sum = 0.0;
   for (int i = 0; i <= n; i++) {
      int numer;
      if (i % 2 == 0) numer = 1;
      else numer = -1;
      sum += (double)numer / (double)fac(i);
   }
   // cout << "sum: " << sum << endl;
   return (double)n * sum;
}

double rec(double n) {
   if (n == 0) return 1;
   if (n == 1) return 0;
   return (n - 1) * (rec(n - 1) + rec(n - 2));
}

int main() {


   vector<double> v;
   v.push_back(1.0);
   
   for (int i = 1; i <=30; i++) {
      double x = rec((double)i);
      double nump = fac((double)i);
      double p = (double)((double)x / (double)nump);
      v.push_back(1-p);

      // cout << setprecision(8) << fixed << p << endl;
   }

   ll n;
   cin >> n;

   if (n >= 30) {
      cout << setprecision(8) << fixed << v[30] << endl;
   } else {
      cout << setprecision(8) << fixed << v[n] << endl;
   }

   

   
   // ll n;
   // cin >> n;

   // vector<double> v;
   // int i = 1;
   // // double x = derange(i);
   // double x;
   // for (i = 1; i < 20; i++) {
   //    x = derange(i);
   //    cout << x << endl;      
   // }

   // double diff = LIM - y;
   // if (diff < 0) diff *= -1;
   // v.push_back(y);
   // while (diff > EPS) {
   //    i++;
   //    x = derange(i);
   //    y = x / (double)fac(i);
   //    if (y < 0) y *= -1;
   //    v.push_back(y);
   //    diff = LIM - y;
   //    if (diff < 0) diff *= -1;
   //    cout << y << endl;
   // }

   // cout << "final y: " << y << endl;
   
   // int j;
   // for (j = 0; j < v.size(); j++)
   //    cout << "v[j]: " << v[j] << endl;
   // cout << j << endl;
   
   // cout << E << endl;
   // cout << LIM << endl;
   
   return 0;
}
