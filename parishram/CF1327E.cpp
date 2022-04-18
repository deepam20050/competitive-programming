#include "bits/stdc++.h"

using namespace std;

const long long MOD = 998244353;

const int N = 2e5 + 5;

long long p10[N];

int main () {
  int n;
  scanf("%d", &n);
  p10[0] = 1;
  for (int i = 1; i <= n; ++i) {
    p10[i] = 10LL * p10[i - 1] % MOD;
  }
  for (int i = 1; i < n; ++i) {
    long long ans = 2LL * 10LL * 9LL * p10[n - i - 1] % MOD;
    ans += (n - i - 1) * 10LL * 9LL * 9LL * p10[n - i - 2] % MOD;
    ans %= MOD;
    printf("%lld ", ans);
  }
  puts("10");
  return 0;
}
