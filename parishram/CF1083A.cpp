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

const int N = 3e5 + 5;

vector < pii > g[N];
lli dp[N];
int gas[N];
lli ans;

void dfs (int u, int pr = -1) {
  lli mx1 = 0;
  lli mx2 = 0;
  for (auto &[to, w] : g[u]) {
    if (to == pr) continue;
    dfs(to, u);
    if (dp[to] - w > mx1) {
      mx2 = mx1;
      mx1 = dp[to] - w;
    } else {
      mx2 = max(mx2, dp[to] - w);
    }
  }
  ans = max(ans, mx1 + mx2 + gas[u]);
  dp[u] = gas[u] + mx1;
}

int main () {
  int n;
  scanf("%d", &n);
  FOR(i, 1, n + 1) scanf("%d", gas + i);
  FOR(i, 1, n) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    g[a].eb(b, c);
    g[b].eb(a, c);
  }
  dfs(1);
  printf("%lld\n", ans);
  return 0;
}
