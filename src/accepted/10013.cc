// Problem #    : 10013
// Created on   : 2018-07-22 15:21:48
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// need speed on this problem, so need to keep array size small and do the
// addition myself
#define MM 1000001
char a[MM];
char b[MM];

int main() {

  int n;
  scanf("%d", &n);
  while (n--) {
    int m;
    scanf("%d ", &m);
    a[m] = '0', b[m] = '0';
    for (int i = m - 1; i >= 0; i--) {
      scanf("%c %c ", &a[i], &b[i]);
    }

    int carry = 0;
    for (int i = 0; i <= m; i++) {
      int x = carry + (int)(a[i] - '0') + (int)(b[i] - '0');
      carry = (x >= 10) ? 1 : 0;
      a[i] = (char)(x % 10 + '0');
    }

    bool start = false;
    for (int i = m; i >= 0; i--) {
      if (start || a[i] != '0')
        printf("%c", a[i]), start = true;
    }
    printf("\n");
    if (n)
      printf("\n");
  }
  return 0;
}
