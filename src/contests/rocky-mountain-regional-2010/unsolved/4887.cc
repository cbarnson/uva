#include <bits/stdc++.h>
using namespace std;



void toa(int a[12], int x) {
   for (int i = 0; i < 12; i++) {
      int div = 1;
      for (int j = 0; j < i; j++) {
	 div *= 3;
      }
      int quot = x / div;
      a[i] = quot % 3;
   }
}

int toi(int a[12]) {
   int x = a[0];
   for (int i = 1; i < 12; i++) {
      int tt = a[i];
      for (int j = i-1; j >= 0; j--) {
	 tt *= 3;
      }
      x += tt;
   }
   return x;
}

int main() {


   int p[531441]; // 3^12 permutations

   


   return 0;
}
