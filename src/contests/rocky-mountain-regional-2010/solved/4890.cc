// Cody Barnson
// 4890 - Aronson
#include <bits/stdc++.h>
using namespace std;

map<int, string> i_cardinal;
map<string, int> s_cardinal;
map<int, string> i_ordinal;
map<string, int> s_ordinal;

const int NN = 29;
const string cardinal[] = { "one", "two", "three", "four", "five", "six",
			    "seven", "eight", "nine", "ten", "eleven",
			    "twelve", "thirteen", "fourteen", "fifteen",
			    "sixteen", "seventeen", "eighteen", "nineteen",
			    "twenty", "thirty", "forty", "fifty", "sixty",
			    "seventy", "eighty", "ninety", "hundred",
			    "thousand" };

const string ordinal[] = { "first", "second", "third", "fourth", "fifth",
			   "sixth", "seventh", "eighth", "ninth", "tenth",
			   "eleventh", "twelfth", "thirteenth", "fourteenth",
			   "fifteenth", "sixteenth", "seventeenth",
			   "eighteenth", "nineteenth", "twentieth", "thirtieth",
			   "fortieth", "fiftieth", "sixtieth", "seventieth",
			   "eightieth", "ninetieth", "hundredth", "thousandth" };

const int number[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
		       17, 18, 19, 20, 30, 40, 50, 60, 70, 80, 90, 100, 1000 };

void init() {
   // clear
   i_cardinal.clear();
   s_cardinal.clear();
   i_ordinal.clear();
   s_ordinal.clear();

   // fill maps - cardinal and ordinal (2 for each)
   for (int i = 0; i < NN; i++) {
      int val = number[i];
      string s = cardinal[i];
      i_cardinal[val] = s;
      s_cardinal[s] = val;
      s = ordinal[i];
      i_ordinal[val] = s;
      s_ordinal[s] = val;
   }   
}

// e.g. pass 69, adds "sixty nine" to vector
void two_digit(vector<string>& v, int val) {
   int tens = val / 10;
   tens *= 10;
   string s = i_cardinal[tens];
   v.push_back(s);
   
   int ones = val % 10;
   s = i_cardinal[ones];
   v.push_back(s);   
}

// e.g. for 12345, can pass it 12, adds it to vector
void three_digit(vector<string>& v, int val) {
   int hundred_factor = val / 100;
   if (hundred_factor > 0) {
      string s = i_cardinal[hundred_factor];
      v.push_back(s);
      v.push_back("hundred");
   }
   val = val % 100;
   auto it = i_cardinal.find(val);
   if (it != i_cardinal.end()) {
      string s = i_cardinal[val];
      v.push_back(s);
   } else { // not found
      two_digit(v, val);
   }      
}

// given a value between 1 and a million, tokenizes the string as specified
// in the problem description, in cardinal form, then takes the ending
// 'token' and converts it to ordinal form, returns the entire string
string to_ordinal(int val) {

   // build string
   vector<string> v;   
   int value = val;

   int thousand_factor = value / 1000;
   if (thousand_factor == 1000) { // special case, "million"
      v.push_back("million");
      goto end;
   } 
   if (thousand_factor > 0) {
      three_digit(v, thousand_factor);
      v.push_back("thousand");
   }
   // handle bottom 3 digits (e.g. for 12345, **345)
   value = value % 1000;
   if (value > 0) {
      three_digit(v, value);
   }
   
  end:

   string last = v.back();
   v.pop_back();

   while (last == "") {
      last = v.back();
      v.pop_back();
   }
   
   if (last == "million") {
      v.push_back("millionth");
   } else {
      int last_val = s_cardinal[last];
      string s = i_ordinal[last_val];
      v.push_back(s);
   }   
   string str = "";
   for (int i = 0; i < v.size(); i++) {
      string s = v[i];
      if (s != "") {
	 str.append(v[i]);
      }
   }
   return str;
}

int main() {

   // initialize map structures for lookup
   init();

   // setup
   vector<int> ak; // 1, 4, 11, 16, ...
   ak.push_back(0);
   
   queue<int> qak; // processing queue
   queue<string> q;
   q.push("t");
   q.push("is");
   q.push("the");

   int last_ak = -1;
   int q_index = 0;
   while (last_ak < 1000000) {

      // string queue, q
      while (!q.empty()) {
	 string s = q.front();
	 q.pop();
	 for (int i = 0; i < s.length(); i++) {
	    if (s[i] == 't') {
	       int new_ordinal = q_index + i + 1;
	       qak.push(new_ordinal);
	    }
	 }
	 q_index += s.length();
      }
      // ak queue (qak), fills q again
      while (!qak.empty()) {
	 int value = qak.front();
	 qak.pop();
	 string s = to_ordinal(value);
	 q.push(s);
	 last_ak = value;
	 ak.push_back(value);
	 if (last_ak >= 1000000)
	    goto done;
      }
   }
  done:
   // QUERIES
   int k;
   while (cin >> k && k != 0) {
      cout << ak[k] << endl;
   }

   return 0;
}
