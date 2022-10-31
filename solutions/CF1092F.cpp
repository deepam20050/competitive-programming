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

const int N = 2e5 + 5;

vector < int > g[N];
lli dp[N], y[N];
int a[N];
lli ans;
int n;
lli tot;

void dfs1 (int u, int p) {
  y[u] = a[u];
  for (auto &to : g[u]) {
    if (to != p) {
      dfs1(to, u);
      y[u] += y[to];
      dp[u] += dp[to] + y[to];
    }
  }
}

void dfs2 (int u, int p, lli up) {
  lli curr = dp[u] + up + tot - y[u];
  ans = max(ans, curr);
  for (auto &to : g[u]) {
    if (to != p) {
      dfs2(to, u, curr - (dp[to] + y[to]));
    }
  }
}


int main () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
    tot += a[i];
  }
  FOR(i, 1, n) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].eb(b);
    g[b].eb(a);
  }
  dfs1(1, 1);
  dfs2(1, 1, 0);
  printf("%lld\n", ans);
  return 0;
}
