#include <bits/stdc++.h>
using namespace std;

int main() {

   
   string str;
   cin >> str;

   string::size_type sz;
   
   int number = stoi(str, &sz);

   cout << "number value: " << number << endl;
   cout << "non-number value: " << str.substr(sz) << endl;
   

   return 0;
}
