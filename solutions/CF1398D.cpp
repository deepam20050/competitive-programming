// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;

const int N = 205;

lli dp[N][N][N];
int a[3][N];
int n[3];

lli solve (int i, int j, int k) {
  if ((i == 0) + (j == 0) + (k == 0) >= 2) return 0;
  auto &ret = dp[i][j][k];
  if (ret != -1) return ret;
  ret = 0;
  if (i >= 1 && j >= 1) ret = max(ret, a[0][i] * 1ll * a[1][j] + solve(i - 1, j - 1, k));
  if (i >= 1 && k >= 1) ret = max(ret, a[0][i] * 1ll * a[2][k] + solve(i - 1, j, k - 1));
  if (j >= 1 && k >= 1) ret = max(ret, a[1][j] * 1ll * a[2][k] + solve(i, j - 1, k - 1));
  return ret;
}

int main () {
  FOR(i, 0, 3) scanf("%d", n + i);
  FOR(i, 0, 3) {
    FOR(j, 1, n[i] + 1) scanf("%d", &a[i][j]);
    sort(a[i] + 1, a[i] + n[i] + 1);
  }
  memset(dp, -1, sizeof dp);
  printf("%lld\n", solve(n[0], n[1], n[2]));
  return 0;
}