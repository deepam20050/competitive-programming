#include "bits/stdc++.h"

using namespace std;

int main() {
  long long n, k;
  scanf("%lld %lld", &n, &k);
  long long calc[5];
  calc[1] = 1;
  calc[2] = (n * (n - 1)) >> 1;
  calc[3] = (n * (n - 1) * (n - 2)) / 3;
  calc[4] = (n * (n - 1) * (n - 2) * (n - 3)) / 24 * 9;
  long long ans = 0;
  for (int i = 1; i <= k; ++i) {
    ans += calc[i];
  }
  printf("%lld", ans);
  return 0;
}