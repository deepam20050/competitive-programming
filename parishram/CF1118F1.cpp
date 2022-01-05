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
const int C = 3;

vector < int > g[N];
int color[N];
int dp[N][C];
int ans;
int n;

void dfs (int u, int pr = -1) {
  FOR(i, 0, C) dp[u][i] = color[u] == i;
  for (auto &to : g[u]) {
    if (to == pr) continue;
    dfs(to, u);
    FOR(i, 0, C) {
      dp[u][i] += dp[to][i];
    }
  }
}

void dfs2 (int u, int pr = -1) {
  for (auto &to : g[u]) {
    if (to == pr) continue;
    if (!dp[to][1] && !dp[to][2]) {
      ans += (dp[1][1] && !dp[1][2]) || (!dp[1][1] && dp[1][2]) || (!dp[1][1] && !dp[1][2]);
    } else if (!dp[to][1] && dp[to][2]) {
      ans += !(dp[1][2] - dp[to][2]); 
    } else if (dp[to][1] && !dp[to][2]) {
      ans += !(dp[1][1] - dp[to][1]);
    }
    dfs2(to, u);
  }
}

int main () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) scanf("%d", color + i);
  FOR(i, 1, n) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].eb(b);
    g[b].eb(a);
  }
  dfs(1);
  dfs2(1);
  printf("%d\n", ans);
  return 0;
}
