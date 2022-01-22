#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 505;

int x[N], speed[N];
int n, l, k;
lli dp[N][N], s[N];
int prev_s[N][N], prev_x[N][N];

int main () {
  scanf("%d %d %d", &n, &l, &k);
  FOR(i, 1, n + 1) {
    scanf("%d", x + i);
  }
  x[n + 1] = l;
  FOR(i, 1, n + 1) {
    scanf("%d", speed + i);
  }
  for (int i = n; i >= 1; --i) {
    s[i] = s[i + 1] + 1ll * (x[i + 1] - x[i]) * speed[i];
  }
  FOR(i, 0, N) FOR(j, 0, N) {
    dp[i][j] = prev_s[i][j] = prev_x[i][j] = 1e9;
  }
  dp[1][0] = 0;
  prev_s[1][0] = speed[1];
  prev_x[1][0] = x[1];
  lli ans = s[1];
  FOR(i, 2, n + 1) {
    dp[i][0] = s[1] - s[i];
    prev_s[i][0] = speed[i];
    prev_x[i][0] = x[i];
    FOR(r, 1, k + 1) {
      // not removed
      dp[i][r] = dp[i - 1][r] + prev_s[i - 1][r] * 1ll * (x[i] - x[i - 1]);
      prev_s[i][r] = speed[i];
      prev_x[i][r] = x[i];
      ans = min(ans, dp[i][r] + s[i]);
      // if removed
      lli tmp = dp[i - 1][r - 1] + prev_s[i - 1][r - 1] * 1ll * (x[i] - x[i - 1]);
      if (tmp <= dp[i][r]) {
        dp[i][r] = tmp;
        prev_s[i][r] = prev_s[i - 1][r - 1];
        prev_x[i][r] = prev_x[i - 1][r - 1];
        ans = min(ans, dp[i][r] + s[i + 1] + prev_s[i - 1][r - 1] * 1ll * (x[i + 1] - x[i]));
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
