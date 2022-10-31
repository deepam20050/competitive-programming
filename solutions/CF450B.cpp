#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;
int main () {
  int f1, f2, n;
  scanf("%d %d %d", &f1, &f2, &n);
  if ((n / 3) & 1) {
    int k = n % 3;
    if (k == 0) {
      printf("%lld", 1ll * ((f2 - f1) % MOD + MOD) % MOD);
    } else if (k == 1) {
      printf("%lld", 1ll * (-f1 + MOD) % MOD);
    } else {
      printf("%lld", 1ll * (-f2 + MOD) % MOD);
    }
  } else {
    int k = n % 3;
    if (k == 0) {
      printf("%lld", 1ll * ((f1 - f2) % MOD + MOD) % MOD);
    } else if (k == 1) {
      printf("%lld", 1ll * (f1 + MOD) % MOD);
    } else {
      printf("%lld", 1ll * (f2 + MOD) % MOD);
    }
  }
  return 0;
}
