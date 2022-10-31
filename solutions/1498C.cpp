#include "bits/stdc++.h"

using namespace std;

const long long MOD = 1e9 + 7;
const int N = 1005;

long long p[2][N];

int mod (int x) {
  return x % MOD;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, k;
    scanf("%d %d", &n, &k);
    long long ans = 1;
    if (k == 1) {
      printf("%lld\n", ans);
      continue;
    }
    ans += n;
    memset(p, 0, sizeof p);
    for (int i = 1; i < n; ++i) {
      p[1][i] = 1;
    }
    for (int i = 2; k > i; ++i) {
      if (i & 1) {
        long long pref = 0;
        for (int j = 1; j < n; ++j) {
          pref += p[0][j - 1];
          pref %= MOD;
          p[1][j] = pref;
          ans += pref;
          ans %= MOD;
        }
      } else {
        long long suff = 0;
        for (int j = n - 1; j >= 0; --j) {
          suff += p[1][j + 1];
          suff %= MOD;
          p[0][j] = suff;
          ans += suff;
          ans %= MOD;
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}