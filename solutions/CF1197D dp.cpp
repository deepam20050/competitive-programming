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

const int N = 3e5 + 5;

int n, m, k;
int a[N];
lli p[N];
lli dp[N];

lli sum (int l, int r) {
  l = max(0, l - 1);
  if (l > r) return 0;
  return p[r] - p[l];
}

int main () {
  scanf("%d %d %d", &n, &m, &k);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
    p[i] = p[i - 1] + a[i];
  }
  lli ans = 0;
  FOR(i, 1, n + 1) {
    FOR(j, 1, m + 1) {
      if (i - j < 0) {
        dp[i] = max(dp[i], sum(1, i) - k);
      } else {
        dp[i] = max(dp[i], sum(i - j + 1, i) - k + dp[i - j]);
      }
    }
    ans = max(ans, dp[i]);
  }
  printf("%lld\n", ans);
  return 0;
}
