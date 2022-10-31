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

const int N = 105;
const int MAX = 105 * 105;

int n;
int a[N], b[N];
bool dp[N][MAX];

int sqr (int x) {
  return x * x;
}

void solve () {
  scanf("%d", &n);
  int add = 0;
  int net_s = 0;
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
    add += sqr(a[i]);
    net_s += a[i];
  }
  FOR(i, 1, n + 1) {
    scanf("%d", b + i);
    add += sqr(b[i]);
    net_s += b[i];
  }
  memset(dp, 0, sizeof dp);
  dp[1][a[1]] = dp[1][b[1]] = 1;
  FOR(i, 2, n + 1) {
    FOR(w, 0, MAX) {
      if (w >= a[i]) {
        dp[i][w] |= dp[i - 1][w - a[i]];
      }
      if (w >= b[i]) {
        dp[i][w] |= dp[i - 1][w - b[i]];
      }
    }
  }
  int ans = 2e9;
  FOR(s, 0, MAX) {
    if (dp[n][s]) {
      ans = min(ans, sqr(s) + sqr(net_s - s));
    }
  }
  printf("%d\n", ans + add * (n - 2));
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
