//================================
//UVA problem#: 11947
//CPSC 3200,	2017-01-15
//Cody Barnson,	ID#001172313
//================================
#include <bits/stdc++.h>
using namespace std;

// note: "could have used Howards Date class; there are other ways to parse
// the input"
int common[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
vector<pair<string, int>> z = {
   make_pair("aquarius", 21),
   make_pair("pisces", 20),
   make_pair("aries", 21),
   make_pair("taurus", 21),
   make_pair("gemini", 22),
   make_pair("cancer", 22),
   make_pair("leo", 23),
   make_pair("virgo", 22),
   make_pair("libra", 24),
   make_pair("scorpio", 24),
   make_pair("sagittarius", 23),
   make_pair("capricorn", 23)
};

bool IsLeap(int y) {
   if (y % 4 != 0) {
      return false;
   } else if (y % 100 != 0) {
      return true;
   } else if (y % 400 != 0) {
      return false;    
   } else {
      return true;
   }  
}

void PrintDate(int m, int d, int y) {
   cout << setfill('0') << setw(2) << m;
   cout << "/" << setfill('0') << setw(2) << d;
   cout << "/" << setfill('0') << setw(4) << y << " ";
}

int main() {


   int n; cin >> n;
   int testcase = 1;
   while (n--) {
      cout << testcase++ << " ";
      string str; cin >> str;
      string mm = str.substr(0, 2); 
      string dd = str.substr(2, 2);
      string yy = str.substr(4, 4);

      int m = stoi(mm); // 1, 2, ... 12
      int d = stoi(dd); // 1, 2, ...
      int y = stoi(yy);

      // max days per month for the first year and the following year
      int dpm[2][12];
      copy(common, common+12, dpm[0]);
      copy(common, common+12, dpm[1]);
    
      // leap year calculation
      if (IsLeap(y)) 
	 dpm[0][1] = 29;      
      if (IsLeap(y+1)) 
	 dpm[1][1] = 29;

      // for indexing dpm
      int yindex = 0; 
      // 10 iterations of progressing 28 days forward on the calendar results
      // the birth date we want to find.
      for (int i = 0; i < 10; i++) {
	 int next = 28 - (dpm[yindex][m-1] - d);

	 if (next < 1) {
	    d = dpm[yindex][m-1] + next;
	 } else {
	    if (m == 12) {
	       yindex++; y++; m = 1;
	    } else {
	       m++;
	    }
	    d = next;
	 }
	 
      }
      
      // result date MM/DD/YYYY
      PrintDate(m, d, y);

      // evaluate zodiac sign
      // the "forward" month, and the "backward" month
      int fm = m-1;
      int bm = (fm == 0) ? 11 : (fm-1);

      if (d >= z[fm].second) {
	 cout << z[fm].first << endl;
      } else {
	 cout << z[bm].first << endl;
      }
   }


   return 0;
}
