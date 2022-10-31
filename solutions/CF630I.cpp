#include "bits/stdc++.h"

using namespace std;

long long binpow (long long x, int n) {
  long long ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

int main () {
  int n;
  scanf("%d", &n);
  long long ans = 2 * 4 * 3 * binpow(4, n - 3) + (n - 3) * 4 * 9 * binpow(4, n - 4);
  printf("%lld\n", ans);
  return 0;
}