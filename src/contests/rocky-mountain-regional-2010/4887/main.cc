#include <bits/stdc++.h>
using namespace std;

// result
// 0 - win for team a
// 1 - draw
// 2 - loss for team a

vector<int> hi;
vector<int> lo;

map<string, int> s_team;
vector<string> v_team;
int score[20];
int n;



struct game {
   int a, b, x; // team a, team b, result (-1 for not played)
   game(int A, int B, int C=-1) : a(A), b(B), x(C) { }   
};

vector<game> unknown;

void update(int arr[20], int num) { // check for new best and new low
   int s[20];
   for (int i = 0; i < num; i++) {
      s[i] = score[i];
   }   
   for (int i = 0; i < num; i++) {
      if (arr[i] == 0) { // win for team a, for unknown[i]
	 s[unknown[i].a] += 3;
      } else if (arr[i] == 1) { // draw
	 s[unknown[i].a] += 1;
	 s[unknown[i].b] += 1;
      } else if (arr[i] == 2) { // lose for team a
	 s[unknown[i].b] += 3;
      } else {
	 assert(0);
      }
   }
   // update
   
}

void rec(int arr[20], int num, int d) {
   if (d > num)  // done
      return;           
   arr[d] = 0;
   rec(arr, num, d+1);
   update(arr, num);
   arr[d] = 1;
   rec(arr, num, d+1);
   update(arr, num);
   arr[d] = 2;
   rec(arr, num, d+1);
   update(arr, num);
}

int main() {

   int m;
   while (cin >> n >> m && !(n == 0 && m == 0)) {

      // 2 <= n <= 20
      // 1 <= m <= 1000

      // n lines
      // map<string, int> s_team;
      // vector<string> v_team;
      s_team.clear();
      v_team.clear();
      unknown.clear();
      hi.clear();
      lo.clear();
      
      for (int i = 0; i < n; i++) {
	 string s; cin >> s;
	 s_team[s] = i;
	 v_team.push_back(s);
	 cout << s << " " << i << endl;
      }      
      
      // m lines
      // int score[20];
      fill(score, score+20, 0);
      for (int i = 0; i < m; i++) {

	 string a, b;
	 cin >> a >> b >> ws;
	 getline(cin, b, ':');
	 int x, y;
	 cin >> x >> y; // x score for a, y score for b
	 cout << a << ", " << b << ": " << x << " " << y << endl;
	 
	 if (x == -1 && y == -1) { // add to unknowns for this
	    unknown.push_back(game(s_team[a], s_team[b]));
	 } else if (x > y) { // team a win
	    score[s_team[a]] += 3;
	 } else if (x < y) { // team a lose
	    score[s_team[b]] += 3;
	 } else { // draw
	    score[s_team[a]] += 1;
	    score[s_team[b]] += 1;
	 }
	 
      }
      // init hi and lo for scores
      for (int i = 0; i < n; i++) {
	 hi.push_back(score[i]);
	 lo.push_back(score[i]);	 
      }
      
      int arr[20];
      fill(arr, arr+20, 0);
      
      

   }


   return 0;
}


 // for (int i = 0; i < n; i++) {
      // 	 cout << "score " << i << ": " << score[i] << endl;
      // }

      // setup for checking options
      // SIZE = unknown.size();
      // for (int i = 0; i < SIZE; i++) {
      // 	 p.push_back(3); // 3 options per unknown
      // }

// vector<int> p;
// int SIZE;

// void toa(vector<int>& a, int x) {
//    for (int i = 0; i < SIZE; i++) {
//       int divisor = 1;
//       for (int j = 0; j < i; j++) {
// 	 divisor *= p[j];
//       }
//       int quot = x / divisor;
//       a[i] = quot % p[i];
//    }
// }

// int toi(vector<int>& a) {
//    int x = a[0];
//    for (int i = 1; i < SIZE; i++) {
//       int tt = a[i];
//       for (int j = i-1; j >= 0; j--) {
// 	 tt *= p[j];
//       }
//       x += tt;
//    }
//    return x;
// }
