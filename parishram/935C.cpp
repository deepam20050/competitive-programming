#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

const double pi = acos(-1.0);

double r, x1, y11, x2, y2;

double sqr (double x) {
  return x * 1.0 * x;
}

double dist (double x, double y, double x0, double y0) {
  return sqrt(sqr(x - x0) + sqr(y - y0));
}

void print (double x, double y, double rr) {
  printf("%.9lf %.9lf %.9lf\n", x, y, rr);
  exit(0);
}

double arctan (double x, double y) {
  if (x == 0) {
    return y > 0 ? pi / 2.0 : -pi / 2.0;
  }
  return atan((y * 1.0 )/ (x * 1.0));
}

int main () {
  scanf("%lf %lf %lf %lf %lf", &r, &x1, &y11, &x2, &y2);
  x2 -= x1; y2 -= y11;
  if (dist(0, 0, x2, y2) >= r) {
    print(x1, y11, r);
  }
  if (x2 == 0 && y2 == 0) {
    print(x1 * 1.0 + r * 0.5, y11 * 1.0, r * 0.5);
  }
  double theta = arctan(x2, y2);
  double x = -r * 1.0 * cos(theta), y = -r * 1.0 * sin(theta);
  if (dist(x, y, x2, y2) < dist(-x, -y, x2, y2)) {
    x = -x;
    y = -y;
  }
  x += x2; y += y2;
  x *= 0.5; y *= 0.5;
  x += x1; y += y11;
  x2 += x1; y2 += y11;
  double rr = dist(x, y, x2, y2);
  print(x, y, rr);
  return 0;
}