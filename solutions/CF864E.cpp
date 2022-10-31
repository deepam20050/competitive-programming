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

tuple < int, int, int, int > a[N];
int dp[N][2005];
int n;
vector < int > ans;

int solve (int pos, int tt) {
  if (pos > n) return 0;
  auto [d, i, t, p] = a[pos];
  if (tt > get<0>(a[n])) {
    return 0;
  }
  if (dp[pos][tt] != -1) {
    return dp[pos][tt];
  }
  int x = solve(pos + 1, tt);
  if (tt + t < d) {
    x = max(x, solve(pos + 1, tt + t) + p);
  }
  return dp[pos][tt] = x;
}

void go (int pos, int tt) {
  if (pos > n || tt > get<0>(a[n])) {
    return;
  }
  if (solve(pos + 1, tt) == solve(pos, tt)) {
    go(pos + 1, tt);
    return;
  }
  ans.eb(get<1>(a[pos]));
  go(pos + 1, tt + get<2>(a[pos]));
}

int main () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    int t, d, p;
    scanf("%d %d %d", &t, &d, &p);
    a[i] = {d, i, t, p};
  }
  sort(a + 1, a + n + 1);
  memset(dp, -1, sizeof dp);
  printf("%d\n", solve(1, 0));
  go(1, 0);
  printf("%d\n", sz(ans));
  for (auto &e : ans) {
    printf("%d ", e);
  }
  return 0;
}
