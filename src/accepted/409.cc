//================================
//UVA problem#: 409
//CPSC 3200,	2017-01-13
//Cody Barnson,	ID#001172313
//================================
#include <bits/stdc++.h>
using namespace std;

typedef map<string, int> mmap;

int main () {

  int testcase = 1;
  int k = 0, e = 0;
  while (cin >> k >> e) {
    cout << "Excuse Set #" << testcase++ << endl;
    cin.ignore();

    // store all keywords and all excuses (possible for a 20-way tie so
    // we must keep this information
    string key[20];
    string exc[20];      

    // keywords
    for (int i = 0; i < k; i++) {
      getline(cin, key[i]);
    }

    // Track the indices, relating to array exc, of the 'worst' excuses
    vector<int> ans;
    int max = 0;

    // excuses
    for (int i = 0; i < e; i++) {
      // each excuse:
      // 1. store original
      // 2. make a copy
      // 3. transform all letters of the copy to lowercase
      // 4. replace all non-alphabetical chars of copy to spaces
      mmap mymap;
      getline(cin, exc[i]);
      string s = exc[i];
      transform(s.begin(), s.end(), s.begin(), ::tolower);
      replace_if(s.begin(), s.end(), [](char c) { return (!isalpha(c)); }, ' ');
      istringstream iss(s);
      while (iss >> s) {
	mymap[s] += 1;
      }

      // take sum of occurences in excuse for each keyword
      int count = 0;
      for (int j = 0; j < k; j++) {
	auto it = mymap.find(key[j]);
	if (it != mymap.end()) {
	  count += (*it).second;
	}
      }

      // if we have nothing else, this is our worst
      if (ans.empty()) {
	max = count;
	ans.push_back(i);
	continue;
      }

      // strictly greater, clear vector; equal to, append
      if (count > max) {
	max = count;
	ans.clear();
	ans.push_back(i);
      } else if (count == max) {
	ans.push_back(i);
      }
    }
    
    for (unsigned int i = 0; i < ans.size(); i++) 
      cout << exc[ans[i]] << endl;

    // "After each set of output, you should print a blank line."
    cout << endl;

  }

  return 0;
}
