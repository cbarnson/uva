// Problem #    : 438
// Created on   : 2018-07-17 18:59:43

#include <algorithm>
#include <assert.h>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <utility>
#include <vector>

using namespace std;

/* how close to call equal */
const double EPSILON = 1E-8;

double PI = acos(-1.0);

struct Point {
  double x, y;
};

int circle(Point p1, Point p2, Point p3, Point &center, double &r) {
  double a, b, c, d, e, f, g;

  a = p2.x - p1.x;
  b = p2.y - p1.y;
  c = p3.x - p1.x;
  d = p3.y - p1.y;
  e = a * (p1.x + p2.x) + b * (p1.y + p2.y);
  f = c * (p1.x + p3.x) + d * (p1.y + p3.y);
  g = 2.0 * (a * (p3.y - p2.y) - b * (p3.x - p2.x));
  if (fabs(g) < EPSILON) {
    return 0;
  }
  center.x = (d * e - b * f) / g;
  center.y = (a * f - c * e) / g;
  r = sqrt((p1.x - center.x) * (p1.x - center.x) +
           (p1.y - center.y) * (p1.y - center.y));
  return 1;
}

int main(void) {
  Point a, b, c, center;
  double r;

  while (cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y) {
    if (circle(a, b, c, center, r)) {
      // cout << fixed << setprecision(3);
      // cout << "center = (" << center.x << ", " << center.y << ")" << endl;
      // cout << "radius = " << r << endl;
      cout << setprecision(2) << fixed << 2 * PI * r << endl;
    } else {
      cout << "colinear" << endl;
    }
  }
  return 0;
}
