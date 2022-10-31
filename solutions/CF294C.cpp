#include "bits/stdc++.h"

using namespace std;

const int N = 1e3 + 5;
const int MOD = 1e9 + 7;

int pascal[N][N], f[N];
bitset < N > on;
int n, m;

void precalc () {
  pascal[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    pascal[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      pascal[i][j] = (pascal[i - 1][j] + pascal[i - 1][j - 1]) % MOD;
    }
  }
  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i <= n; ++i) {
    f[i] = (f[i - 1] + f[i - 1]) % MOD;
  }
}

void mul (int &x, int y) {
  x = 1ll * x * y % MOD;
}

int main () {
  scanf("%d %d", &n, &m);
  precalc();
  for (int i = 0; i < m; ++i) {
    int x;
    scanf("%d", &x);
    on[--x] = 1;
  }
  int pref = 0, idx = 0;
  while (idx < n && !on[idx]) {
    ++pref;
    ++idx;
  }
  int suff = 0;
  idx = n - 1;
  while (idx >= 0 && !on[idx]) {
    ++suff;
    --idx;
  }
  int len = n;
  n -= m;
  int ans = 1;
  mul(ans, pascal[n][pref]);
  n -= pref;
  mul(ans, pascal[n][suff]);
  n -= suff;
  for (int i = 0, l = -1; i < len; ++i) {
    if (on[i]) {
      if (l == -1) {
        l = i;
      } else {
        int k = i - l - 1;
        mul(ans, pascal[n][k]);
        mul(ans, f[k]);
        n -= k;
        l = i;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
