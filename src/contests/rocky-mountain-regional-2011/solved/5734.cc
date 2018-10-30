// Cody Barnson
// 5734 - Shape number
#include <bits/stdc++.h>
using namespace std;

char steps(char a, char b) {
  // a and b are DIRECTIONS 0 to 7, circularly, forward is CCW
  int x = a - '0';
  int y = b - '0';
  int c = 0;
  while (x != y) {
    x = (x + 1) % 8;
    c++;
  }
  char ret = c + 48;
  return ret;
}

// pos = position of the start of the lexicographically least rotation
// period = the period
void compute(string s, int &pos, int &period) {
  s += s;
  int len = s.length();
  int i = 0, j = 1;
  for (int k = 0; i + k < len && j + k < len; k++) {
    if (s[i + k] > s[j + k]) {
      i = max(i + k + 1, j + 1);
      k = -1;
    } else if (s[i + k] < s[j + k]) {
      j = max(j + k + 1, i + 1);
      k = -1;
    }
  }

  pos = min(i, j);
  period = (i > j) ? i - j : j - i;
}

int main() {
  string str;
  while (getline(cin, str) && str != "") {
    // save original length, copy to string representing our first difference
    int NN = str.length();
    string firstdiff = str;

    // ith entry in first distance array is equal to the number of CCW steps
    // required to get from the direction represented by str[i] to the direction
    // represented by str[i+1]
    for (int i = 0; i < NN - 1; i++) {
      firstdiff[i] = steps(str[i], str[i + 1]);
    }
    firstdiff[NN - 1] = steps(str[NN - 1], str[0]);

    // using code from str_rotation_period.cc in code library.
    // Computes the lexicographically least rotation of a string with O(n) time
    // complexity
    int pos, period;
    compute(firstdiff, pos, period);
    firstdiff += firstdiff;
    cout << firstdiff.substr(pos, NN) << endl;
    str = "";
  }

  return 0;
}
