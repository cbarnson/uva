// Cody Barnson
// 5739 - User Names
#include <bits/stdc++.h>
using namespace std;

// HOWARDS FEEDBACK
// very nicely done.  With some thinking, you turned this potentially nasty
// and messy problem into something that is very clean.
int main() {
   int n, MM, cn = 1;
   while (cin >> n >> MM && !(n == 0 && MM == 0)) {      
      cout << "Case " << cn++ << endl;
      map<string, int> db; // database

      // for each name, get the first and last name strings, change letters
      // to lowercase, remove ' and - characters, then output the correct
      // string based on the specified max length and existing names
      // in the database map
      for (int i = 0; i < n; i++) {
	 string line;
	 getline(cin >> ws, line);
	 transform(line.begin(), line.end(), line.begin(), ::tolower);
	 auto lend = remove_if(line.begin(), line.end(),
			      [] (char c) { return c == '\'' || c == '-'; });
	 istringstream iss(string(line.begin(), lend));
	 string first, last;
	 iss >> first;
	 while (iss >> last)
	    ;
	 string key = first[0] + last;

	 // if this key already exists in database, append the key's value,
	 // as a string, to the output string, if it is less than the max
	 // output length, otherwise, drop either the last letter, or
	 // the last two letters (if necessary of the last name)
	 string suffix = "";
	 if (db[key]) suffix = to_string(db[key]);
	 copy(begin(key), begin(key) + min((MM - suffix.length()), key.length()),
	      ostream_iterator<char>(cout));
	 cout << suffix << endl;
	 db[key] += 1;
      }
   }

   return 0;
}
