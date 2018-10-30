// Cody Barnson
// 5737 - Pills
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int NN = 31;
ll arr[NN][NN];

// HOWARDS FEEDBACK:
// (1) generally write the recursive function f to also fill the table
// entry just before i return the answer, that way I do not have to write
// a loop outside to fill the DP table; Why important? if you don't fill
// the entire table, and table entry is stored inside f as you compute
// it, it means that only the entries that need to computed will actually be
// computed. Entries that are never asked for are not computed at all.
ll f(int t, int o) {
   // unnecessary, implicitly true
   // if (t < 0 || o < 0 || t >= NN || o >= NN) {
   //    return 0;
   // }      
   if (arr[t][o] != -1) // do we already have a value for this element
      return arr[t][o];      
   if (t == 0)          // No 2's; when all 1's only one way to finish
      return 1;   
   else if (o == 0)     // No 1's; decr 2's, incr 1's
      return f(t-1, o+1);
   else                 // >= 1 each
      return f(t, o-1) + f(t-1, o+1);
}

int main() {
   // set first row (i.e. zero 2's, always 1)
   // mark all spaces where i + j > (NN - 1) as 0, otherwise -1
   fill(arr[0], arr[0]+NN, 1);
   for (int i = 1; i < NN; i++) {
      for (int j = 0; j < NN; j++) {
   	 if (i + j > (NN-1))
   	    arr[i][j] = 0;
	 else
	    arr[i][j] = -1;
      }
   }

   // fill DP table
   for (int i = 1; i < NN; i++) 
      for (int j = 0; j < (NN - i); j++) 
	 arr[i][j] = f(i, j);

   // Queries
   int n;
   while (cin >> n && n != 0) 
      cout << arr[n][0] << endl;

   return 0;
}
