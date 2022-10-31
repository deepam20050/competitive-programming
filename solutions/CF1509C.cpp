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

const int N = 2005;

lli dp[N][N];
int a[N];

lli solve (int l, int r) {
  if (dp[l][r] != -1) {
    return dp[l][r];
  }
  if (l == r) {
    return 0;
  }
  return dp[l][r] = a[r] - a[l] + min(solve(l + 1, r), solve(l, r - 1));
}

int main () {
  int n;
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + n + 1);
  memset(dp, -1, sizeof dp);
  printf("%lld\n", solve(1, n));
  return 0;
}
