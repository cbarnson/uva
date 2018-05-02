#include <bits/stdc++.h>
using namespace std;

// string direction = "xyzabc";
int dx[] = { 1, 0, 0, -1, 0, 0 };
int dy[] = { 0, 1, 0, 0, -1, 0 };
int dz[] = { 0, 0, 1, 0, 0, -1 };

int L;

struct point {
  int x = 1;
  int y = 0;
  int z = 0;
  void update(int i) {
    x = dx[i];
    y = dy[i];
    z = dz[i];
  }
  void print() {
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
  }
  void diff(point a, point b) {
    x = b.x - a.x;
    y = b.y - a.y;
    z = b.z - a.z;
  }
};

int toInt(string s) {
  // cout << "string is '" << s << "'" << endl; 
  int val;
  switch(s.back()) {
    case 'x':
      val = 0;
      break;
    case 'y':
      val = 1;
      break;
    case 'z':
      val = 2;
      break;
  }
  return (s.front() == '-' ? val + 3 : val);
}

void solve(istringstream& iss, point& p, point& prev) {
  string token;
  while (iss >> token) {
    solve(iss, p, prev);
  }
  if (token == "" || token == "No") return;

  int val = toInt(token);
  // cout << "val is " << val << endl;

  prev = p;
  p.update(val);
  p.print();
  return;
  
}

int main() {

  while (cin >> L && L != 0) {
    string s;
    getline(cin >> ws, s);
    point p, prev;
    istringstream iss(s);
    solve(iss, p, prev);
    cout << "curr: ";
    p.print();
    cout << "prev: ";
    prev.print();
    point c;
    c.diff(p, prev);
    cout << "ANSWER: ";
    c.print();
    cout << endl;
  }

  return 0;
}
