#include <bits/stdc++.h>
using namespace std;

string SS[6] = { "1122", "1212", "1221", "2112", "2121", "2211" };

typedef map<string, int> Map;

struct tile {
   bool valid;
   int a, b, c;
   tile(bool v=true) {
      valid = v;
   }
};

struct board {
   tile b[5][5];

   void init() {
      b[0][0].valid = false;
      b[0][1].valid = false;
      b[1][0].valid = false;
      b[3][4].valid = false;
      b[4][3].valid = false;
      b[4][4].valid = false;
   }

   int sumA() {
      int sum = 0;
      sum += b[2][0].a * 3;
      sum += b[2][1].a * 4;
      sum += b[2][2].a * 5;
      sum += b[2][3].a * 4;
      sum += b[2][4].a * 3;
      return sum;
   }

   int sumB() {
      int sum = 0;
      sum += b[2][0].b * 3;
      sum += b[2][1].b * 4;
      sum += b[2][2].b * 5;
      sum += b[2][3].b * 4;
      sum += b[2][4].b * 3;
      return sum;
   }

   int sumC() {
      int sum = 0;
      sum += b[0][2].c * 3;
      sum += b[1][2].c * 4;
      sum += b[2][2].c * 5;
      sum += b[3][2].c * 4;
      sum += b[4][2].c * 3;
      return sum;
   }

   void assignA(int val, int row) {
      b[2][row].a = val;
   }

   void assignB(int val, int row) {
      b[2][row].b = val;
   }

   void assignC(int val, int row) {
      b[row][2].c = val;
   }

   void assign(int val, int row, char ch) {
      switch(ch) {
	 case 'a':
	    b[2][row].a = val;
	    break;
	 case 'b':
	    b[2][row].b = val;
	    break;
	 case 'c':
	    b[row][2].c = val;
	    break;
      }
   }

   bool inbound(int r, int c) {
      if (r < 0 || r > 4 || c < 0 || c > 4) return false;
      return true;
   }

   void upright(int& r, int& c) {
      r -= 1; c += 1;
   }

   void downleft(int& r, int& c) {
      r += 1; c -= 1;
   }
   
   void fill() {
      // a
      for (int i = 0; i < 5; i++) {
	 int x = b[2][i].a;
	 int row = 2, col = i;
	 upright(row, col);
	 while(inbound(row, col)) {
	    b[row][col].a = x;
	    upright(row, col);
	 }
	 row = 2, col = i; // reset
	 downleft(row, col);
	 while(inbound(row, col)) {
	    b[row][col].a = x;
	    downleft(row, col);
	 }
      }

      // b
      for (int i = 0; i < 5; i++) {
	 int x = b[2][i].b;
	 for (int j = 0; j < 5; j++) {
	    b[j][i].b = x;
	 }
      }
      
      // c
      for (int i = 0; i < 5; i++) {
	 int x = b[i][2].c;
	 for (int j = 0; j < 5; j++) {
	    b[i][j].c = x;
	 }
      }
   }

   void printA() {
      cout << "printing A:\n";
      for (int i = 0; i < 5; i++) {
	 for (int j = 0; j < 5; j++) {
	    if (!b[i][j].valid) {
	       cout << "X ";
	       continue;
	    }
	    cout << b[i][j].a << " ";
	 }
	 cout << endl;
      }
   }
   void printB() {
      cout << "printing B:\n";
      for (int i = 0; i < 5; i++) {
	 for (int j = 0; j < 5; j++) {
	    if (!b[i][j].valid) {
	       cout << "X ";
	       continue;
	    }
	    cout << b[i][j].b << " ";
	 }
	 cout << endl;
      }
   }
   void printC() {
      cout << "printing C:\n";
      for (int i = 0; i < 5; i++) {
	 for (int j = 0; j < 5; j++) {
	    if (!b[i][j].valid) {
	       cout << "X ";
	       continue;
	    }

	    cout << b[i][j].c << " ";
	 }
	 cout << endl;
      }
   }
   
   void print() {
      cout << "A: ";
      for (int i = 0; i < 5; i++) {
	 cout << b[2][i].a;
      }
      cout << endl;
      cout << "B: ";
      for (int i = 0; i < 5; i++) {
	 cout << b[2][i].b;
      }
      cout << endl;
      cout << "C: ";
      for (int i = 0; i < 5; i++) {
	 cout << b[i][2].c;
      }
      cout << endl;
   }
  
};

bool cmp(int x, int y) {
   return x > y;
}

void assignSequence(int w, int x, int y, int z, char ch,
		    const vector<int>& dir, board& b) {
   b.assign(dir[w], 0, ch);
   b.assign(dir[x], 1, ch);
   b.assign(dir[y], 3, ch);
   b.assign(dir[z], 4, ch);  
}

void solve(int id) {
   board b;
   b.init();
  
   vector<int> A;
   vector<int> B;
   vector<int> C;

   copy_n(istream_iterator<int>(cin), 3, back_inserter(A));
   copy_n(istream_iterator<int>(cin), 3, back_inserter(B));
   copy_n(istream_iterator<int>(cin), 3, back_inserter(C));

   sort(begin(A), end(A));
   sort(begin(B), end(B));
   sort(begin(C), end(C));


   // always assign the min to row 2 (the one 5 long)
   b.assignA(A[0], 2);
   b.assignB(B[0], 2);
   b.assignC(C[0], 2);

   // for each direction, try the following 6 possibilities
   // 1122
   // 1212
   // 1221
   // 2112
   // 2121
   // 2211

   int max = 0;
   for (int i = 0; i < 6; i++) {
      assignSequence(SS[i][0]-'0', SS[i][1]-'0', SS[i][2]-'0', SS[i][3]-'0', 'a', A, b);
      for (int j = 0; j < 6; j++) {
	 assignSequence(SS[j][0]-'0', SS[j][1]-'0', SS[j][2]-'0', SS[j][3]-'0', 'b', B, b);
	 for (int k = 0; k < 6; k++) {
	    assignSequence(SS[k][0]-'0', SS[k][1]-'0', SS[k][2]-'0', SS[k][3]-'0', 'c', C, b);
	    int result = b.sumA() + b.sumB() + b.sumC();
	    if (result > max) {

	       // up to this point, the board is only partially filled, fill each direction
	       b.fill();

	       // b.printA();
	       // b.printB();
	       // b.printC();
	       
	       Map m;
	       bool valid = true;
	       for (int l = 0; l < 5; l++) {            
		  for (int ll = 0; ll < 5; ll++) {
		     if (!b.b[l][ll].valid) continue;
		     stringstream ss;
		     ss << b.b[l][ll].a << b.b[l][ll].b << b.b[l][ll].c;
		     string str = ss.str();
		     if (m[str] == 1) {
			valid = false;
			break;
		     }
		     m[str] = 1;              
		  }
		  if (!valid) break;
	       }

          
	       if (valid) {
		  max = result;
	       }

	    }
	 }
      }
   }

   cout << "Test #" << id << endl << max << endl << endl;
  
}

int main() {

   int id = 1;
   int cases; cin >> cases;
   while(cases--) {
      solve(id++);
   }

}
