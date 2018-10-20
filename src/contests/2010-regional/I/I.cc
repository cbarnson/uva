#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;

map<int, string> ord = {
   { 1, "first" }, 
   { 2, "second" }, 
   { 3, "third" }, 
   { 4, "fourth" }, 
   { 5, "fifth" }, 
   { 6, "sixth" }, 
   { 7, "seventh" }, 
   { 8, "eighth" }, 
   { 9, "ninth" }, 
   { 10, "tenth" }, 
   { 11, "eleventh" }, 
   { 12, "twelfth" }, 
   { 13, "thirteenth" }, 
   { 14, "fourteenth" }, 
   { 15, "fifteenth" }, 
   { 16, "sixteenth" }, 
   { 17, "seventeenth" }, 
   { 18, "eighteenth" }, 
   { 19, "nineteenth" }, 
   { 20, "twentieth" }, 
   { 30, "thirtieth" }, 
   { 40, "fortieth" }, 
   { 50, "fiftieth" }, 
   { 60, "sixtieth" }, 
   { 70, "seventieth" }, 
   { 80, "eightieth" }, 
   { 90, "ninetieth" }, 
   { 100, "hundredth" }, 
   { 1000, "thousandth" }
};

map<int, string> card = {
   { 1, "one" }, 
   { 2, "two" }, 
   { 3, "three" }, 
   { 4, "four" }, 
   { 5, "five" }, 
   { 6, "six" }, 
   { 7, "seven" }, 
   { 8, "eight" }, 
   { 9, "nine" }, 
   { 10, "ten" }, 
   { 11, "eleven" }, 
   { 12, "twelve" }, 
   { 13, "thirteen" }, 
   { 14, "fourteen" }, 
   { 15, "fifteen" }, 
   { 16, "sixteen" }, 
   { 17, "seventeen" }, 
   { 18, "eighteen" }, 
   { 19, "nineteen" }, 
   { 20, "twenty" }, 
   { 30, "thirty" }, 
   { 40, "forty" }, 
   { 50, "fifty" }, 
   { 60, "sixty" }, 
   { 70, "seventy" }, 
   { 80, "eighty" }, 
   { 90, "ninety" }, 
   { 100, "hundred" }, 
   { 1000, "thousand" }
};

string str = "tisthe";




// string card100(int i) {
//    if (i == 0) return "";
//    if (i <= 20 || (i % 10 == 0 && i < 100) || i == 1000) {
//       return card[i];
//    }

//    if (i == 100) return "onehundred";

//    if (i < 100) {
//       int y = i % 10;
//       int x = (i / 10) * 10;
//       return card[x] + card[y];
//    }   
// }

string getcard(int i) {
   if (i <= 20 || (i % 10 == 0 && i < 100)) {
      return card[i];
   }

   if (i == 1000) return "onethousand";
   if (i == 1000000) return "onemillion";
   string s = "";
   
   // thousands
   int t = i / 1000;
   if (t > 0) {
      s += getcard(t) + "thousand";
   }

   int h = i % 1000;
   int x = h / 100;
   if (x > 0) {
      s += card[x] + card[100];
   }

   x = h % 100;
   if (x > 0) {

      int k = x % 10;
      int j = (x / 10) * 10;
      s += getcard(j) + getcard(k);
   }
   
   return s;
}


string getord(int i) {
   if (i <= 20 || (i % 10 == 0 && i < 100)) {
      return ord[i];
   }

   if (i == 1000) return "onethousandth";
   if (i == 1000000) return "onemillionth";
   string s = "";

   // thousands XXX,xxx
   int t = i / 1000;
   int h = i % 1000;
   if (t > 0) {
      s += getcard(t) + "thousand";
      if (h == 0) {
	 s += "th";
	 return s;
      }
   }

   // 1 <= h <= 999

   int a = (h / 100) * 100;
   if (a > 0) {
      if (a < h) {
	 s += getcard(a);
      } else {
	 s += getcard(a) + "th";
	 return s;
      }
   }

   // 1 <= tens <= 99
   int tens = h % 100;

   if (tens <= 20) {
      s += getord(tens);
      return s;
   }
   
   int b = (tens / 10) * 10;
   if (b > 0) {
      if (b < tens) {
	 s += getcard(b);
      } else {
	 s += getord(b);
	 return s;
      }
   }

   int ones = tens % 10;
   int c = ones;
   s += ord[c];
   return s;
}



int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   // cout << getord(1000) << endl;
   // return 0;
   
   // int N = 1000;
   // for (int i = 1; i <= N; i++) {
   //    cout << i << " : " << getord(i) << endl;
   // }
   // return 0;

   vi A;
   
   int j = 0, i = 0;
   while (j < 100000 && i < 1000001) {

      while (str[i] != 't') {
	 i++;
      }
      // cout << i + 1 << " ";
      str += getord(i+1);
      A.push_back(i+1);
      j++; i++;
   }


   FR(i, 20) {
      cout << A[i] << " ";
   }
   cout << endl;
   return 0;
   
   int n;
   while (cin >> n) {
      if (!n) break;
      cout << A[n-1] << endl;
   }

   
   
}
