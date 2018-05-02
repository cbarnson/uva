#include <bits/stdc++.h>
using namespace std;

//int food[] = { 0, 1, 2, 3, 4 }; // fat, pro, sug, sta, alc

double gramToCal(string s, int type) {
   assert(s.size() > 1);
   string str(s.begin(), s.end()-1);
   double gram = stod(str);

   if (type == 0) {
      // fat
      return gram * 9;
   } else if (type == 4) {
      // alc
      return gram * 7;
   } else {
      // pro, sug, sta
      return gram * 4;
   }   
}

void changeGramToCal(vector<string>& t) {
   for (int i = 0; i < t.size(); i++) {
      char ch = t[i].back();
      if (ch == 'g') {
	 double cals = gramToCal(t[i], i%5);
	 t[i] = to_string(cals) + "C";
      }
   }
}

bool isPercent(string s) {
   return (s.back() == '%');
}

bool isCal(string s) {
   return (s.back() == 'C');
}

int getTotalCal(const vector<string>& t) {
   int total = 0;
   for (int i = 0; i < t.size(); i++) {
      if (isCal(t[i])) {
	 total += stoi(string(t[i].begin(), t[i].end()-1));
      }
   }
   return total;
}

int getCal(string s) {
   return stoi(string(s.begin(), s.end()-1));
}

string toPercent(double percent) {
   return to_string(percent) + "%";
}

void changeToPercent(vector<string>& t) {
   int per1; // ones already percents
   for (int i = 0; i < t.size(); i++) {
      if (isPercent(t[i])) {
	 per1 += stoi(string(t[i].begin(), t[i].end()-1));
      } 
   }
   int per2 = 100-per1;

   int cTotal = getTotalCal(t);
   for (int i = 0; i < t.size(); i++) {
      if (isCal(t[i])) {
	 // change
	 double newPercent = static_cast<double>(getCal(t[i])) * static_cast<double>(per2) / static_cast<double>(cTotal);
	 t[i] = toPercent(newPercent);
      }
   }
}

int getTCals(const vector<string>& t) {
   int per1; // ones already percents
   for (int i = 0; i < t.size(); i++) {
      if (isPercent(t[i])) {
	 per1 += stoi(string(t[i].begin(), t[i].end()-1));
      } 
   }
   int per2 = 100-per1;
   int cTotal = getTotalCal(t);

   double result = static_cast<double>(100 * cTotal / per2);
   //cout << "total cals: " << result << endl;
   return static_cast<int>(result);
}

bool solve() {
   
   vector<double> fatPercent;
   vector<int> t_cals;
   
   string temp;
   cin >> temp;
   
   // one time check
   if (temp == "-") { return false; }

   int food_items = 0;
   while (temp != "-") {
      
      vector<string> tokens;
      
      food_items++;
      tokens.push_back(temp);
      // read 4 more things
      for (int i = 0; i < 4; i++) {
	 cin >> temp;
	 tokens.push_back(temp);
      }
      // process this line 
      changeGramToCal(tokens);

      t_cals.push_back(getTCals(tokens));
      
      // change all to percents
      changeToPercent(tokens);

      double fp = stod(string(tokens[0].begin(), tokens[0].end()-1));
      //cout << "adding fat percent: " << fp << endl;
      fatPercent.push_back(fp);
      
      // grab next to check its another line or end of case
      cin >> temp;
   }

   double ans = fatPercent[0];

   if (fatPercent.size() > 1) {
      ans = 0;

      vector<double> weights;
      double food_total = t_cals[0];
      if (t_cals.size() > 1) {
	 food_total = 0;
	 for (int i = 0; i < t_cals.size(); i++) {
	    food_total += t_cals[i];
	 }
      }

      for (int i = 0; i < t_cals.size(); i++) {
	 weights.push_back(t_cals[i] / food_total);
      }
      
      for (int i = 0; i < fatPercent.size(); i++) {
	 //cout << fatPercent[i] << endl;
	 ans += fatPercent[i] * weights[i];
      }
   }

   cout << round(ans) << "%" << endl;

   return true;
}

int main() {

   while (solve())
      ;


}
