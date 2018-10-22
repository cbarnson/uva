// Problem #    : array
// Created on   : 2018-10-16 16:35:12
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   // cin rows, by line, store in 2d vector of strings,

   // first row with have m - 1, leave space for [0,0] (top left corner)

   // output

   // \begin{array}{cc..c} \hline
   // _ & _ & ... & _ \hline
   // ...
   // \end{array}

   // for latex, note is array, so content is math mode

   vector< vector<string> > A;
   
   string s = "";
   int f = 0;
   while (getline(cin, s)) {
      stringstream ss(s);

      vector<string> B;      
      if (!f) B.push_back(""), f = 1;

      string x;
      while (ss >> x) {
	 B.push_back(x);
      }

      A.push_back(B);      
   }

   // print
   int cols = A[0].size();
   int rows = A.size();    // inclusive of header

   const string lb = "\\\\";
   const string hl = "\\hline";

   string colstr = "c";
   FR(i, cols - 1) {
      colstr += string((i ? "|" : "||")) + string("c");
   }

   
   string math_start = "\\[", math_end = "\\]";
   string header = "\\begin{array}";
   string col_spec = "{" + colstr + "}";
   string footer = "\\end{array}";

   // figure
   cout << "\\begin{figure}[H]" << endl;
   cout << "\\centering" << endl;
   cout << endl;
   
   // begin
   cout << math_start << endl << header << col_spec << endl;

   // array body
   
   assert(A.size() == rows);
   for (int i = 0; i < rows; i++) {

      assert(A[i].size() == cols);
      cout << "\t";
      for (int j = 0; j < cols; j++) {
	 if (j) cout << "& ";
	 cout << A[i][j] << " ";
      }
      cout << lb << " ";
      cout << hl << " ";
      if (!i) cout << hl << " ";
      cout << endl;
   }

   // end
   cout << footer << endl << math_end << endl;
   
   // end figure
   cout << endl;
   cout << "\\caption{}" << endl;
   cout << "\\label{fig:mylabel}" << endl;
   cout << "\\end{figure}" << endl;


}
