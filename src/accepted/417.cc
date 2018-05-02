#include <bits/stdc++.h>
using namespace std;

typedef map<string, int> Map;
typedef set<string> Set;

string s = "abcdefghijklmnopqrstuvwxyz";

int main() {

   // fill map 1 to 83681

   // take input string

   // if in map, output value

   // else output '0'


   // ascii, a = 97, z = 122
   Map m;
   Set s;
   // s.insert(make_pair<string, int>("a", 1));
   // s.insert(make_pair<string, int>("b", 2));
   // s.insert(make_pair<string, int>("ab", 27));

   s.insert("a");
   s.insert("b");
   s.insert("ab");

   m["a"] = 1;
   m["b"] = 1;
   m["ab"] = 1;

   for (auto it = m.begin(); it != m.end(); ++it) {
      cout << it->first << " ";
   }
   cout << endl;
   
   // for (auto it = s.begin(); it != s.end(); ++it) {
   //    cout << *it << " ";
   // }
   // cout << endl;
   
   
   

   return 0;
}
