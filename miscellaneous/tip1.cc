// Problem:
// Status :
#include <bits/stdc++.h>
using namespace std;

// init in binary form
// auto num = 0b011

typedef vector<int> vi;

bool isOdd(int num) { return (num & 1); }
int multBy2(int num) { return num << 1; }
int divBy2(int num) { return num >> 1; }
int builtInGCD(int x, int y) { return __gcd(x, y); }
int numberOfDigits(int num) { return floor(log10(num)) + 1; }
bool isPowerOf2(int x) { return x && (!(x & (x - 1))); }; // for positive integers

void print(vector<int> &vec) {
   for (const auto &i : vec)
      cout << i << ' ';
   cout << endl;
}

template<typename T>
void printInitList(initializer_list<T> l) {
   for (const auto &i : l) 
      cout << i << ' ';
   cout << endl;
}

int main() {

   // int n = 15;
   // cout << builtInGCD(15, 3) << endl;

   // cout << numberOfDigits(15) << endl;
   // cout << numberOfDigits(123) << endl;
   // cout << numberOfDigits(500000) << endl;
   // cout << numberOfDigits(1e8) << endl;
   // cout << (int)1e6 << endl;

   // for (int i = 0; i < 100; i++) {
   //    cout << setw(6) << -i << " : " << isPowerOf2(-i) << endl;
   // }
   // cout << endl << endl;
   // cout << isPowerOf2(-2) << endl;

   vector<int> vec { 1,2,3,4,5 };
   print(vec);

   printInitList({4,5,6,7,8});

   // auto num = 0b011;
   // cout << num << endl;
   
   return 0;
}
