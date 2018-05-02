//================================
//UVA problem#: 10420
//CPSC 3200,	2017-01-13
//Cody Barnson,	ID#001172313
//================================
#include <bits/stdc++.h>
using namespace std;

typedef map<string, int> mmap;

int main () {

  mmap m;
  int n;
  cin >> n;
  cin.ignore();
  // grab the entire line, break off the first word, increment its value
  // in the map by 1 ("...name of a woman (the rest of the words in the line")
  // The rest of the string from that line is irrelevant. 
  while (n--) {
    string str, s;
    getline(cin, str);
    istringstream iss(str);    
    iss >> s;
    m[s] += 1;
  }
  // by virtue of storing in a map, simply print from begin to end
  for (auto it : m) {
    cout << it.first << " " << it.second << endl;
  }

  return 0;
}
