#include "bits/stdc++.h"

using namespace std;

double binpow (double x, int n) {
  double ret = 1;
  while (n) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

int main () {
  int m, n;
  scanf("%d %d", &m, &n);
  double ans = 0;
  for (int i = 1; i <= m; ++i) {
    ans += 1.0 * i * (binpow(1.0 * i / (1.0 * m), n) - binpow(1.0 * (i - 1.0) / (1.0 * m), n));
  }
  printf("%.6lf\n", ans);
  return 0;
}
