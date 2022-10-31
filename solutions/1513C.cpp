#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;

const int M = 2e5 + 5;

int dp[10][M];

int f (int d, int len) {
  int &ret = dp[d][len];
  if (len == 0) {
    return ret = 1;
  }
  if (ret != -1) {
    return ret;
  }
  if (d < 9) {
    return ret = f(d + 1, len - 1);
  }
  return ret = (f(1, len - 1) + f(0, len - 1)) % MOD;
}

int main () {
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < M; ++j) {
      f(i, j);
    }
  }
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int x, k;
    scanf("%d %d", &x, &k);
    if (x == 0) {
      printf("%d\n", dp[x][k]);
    } else {
      int ans = 0;
      while (x > 0) {
        ans += dp[x % 10][k];
        ans %= MOD;
        x /= 10;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
