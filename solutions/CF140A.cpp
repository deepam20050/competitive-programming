#include "bits/stdc++.h"

using namespace std;

const double pi = 3.14159265358979323846;

int main () {
  int n, R, r;
  scanf("%d %d %d", &n, &R, &r);
  if (R > r + r) {
    double theta = asin(1.0 * r / (R - r));
    int mx = pi / theta;
    if (abs(ceil(pi / theta) - pi / theta) < 1e-13) {
      ++mx;
    }
    mx >= n ? puts("YES") : puts("NO");
  } else if (R == r + r) {
    n <= 2 ? puts("YES") : puts("NO");
  } else {
    n == 1 && r <= R ? puts("YES") : puts("NO");
  }
  return 0;
}
