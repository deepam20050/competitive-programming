// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int M = 513;
const int inf = 1e9;

int dp[M];

int main () {
  fill(dp, dp + M, inf);
  int n;
  scanf("%d", &n);
  dp[0] = -1;
  FOR(i, 0, n) {
    int x;
    scanf("%d", &x);
    FOR(j, 0, M) {
      int y = j ^ x;
      if (y < M && dp[y] <= x) {
        dp[j] = min(dp[j], x);
      }
    }
  }
  int ans = 0;
  FOR(j, 0, M) ans += dp[j] != inf;
  printf("%d\n", ans);
  FOR(j, 0, M) {
    if (dp[j] != inf) printf("%d ", j);
  }
  return 0;
}
