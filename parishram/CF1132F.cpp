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

int dp[N][N];
char s[N];
int n;

int solve (int l, int r) {
  if (l > r) {
    return 0;
  }
  if (l == r) {
    return 1;
  }
  auto &ret = dp[l][r];
  if (ret != -1) {
    return ret;
  }
  ret = 1 + solve(l + 1, r);
  FOR(i, l + 1, r + 1) {
    if (s[i] == s[l]) {
      ret = min(ret , solve(l + 1, i - 1) + solve(i, r));
    }
  }
  return ret;
}

int main () {
  scanf("%d %s", &n, s + 1);
  memset(dp, -1, sizeof dp);
  printf("%d\n", solve(1, n));
  return 0;
}
