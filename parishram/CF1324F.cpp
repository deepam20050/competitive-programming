// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 2e5 + 5;

int dp[N];
int dp2[N];
int color[N];
vector < int > g[N];
int n;

int dfs (int u, int pr = -1) {
  dp[u] = color[u];
  for (auto &to : g[u]) {
    if (to != pr) {
      int r = dfs(to, u);
      if (r > 0) {
        dp[u] += r;
      }
    }
  }
  return dp[u];
}

void dfs2 (int u, int pr, int up) {
  if (up < 0) up = 0;
  dp2[u] = up;
  for (auto &to : g[u]) {
    if (to != pr) {
      if (dp[to] > 0) {
        dfs2(to, u, up + dp[u] - dp[to]);
      } else {
        dfs2(to, u, up + dp[u]);
      }
    }
  }
}

int main () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", color + i);
    if (!color[i]) color[i] = -1;
  }
  FOR(i, 1, n) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].eb(b);
    g[b].eb(a);
  }
  dfs(1);
  dfs2(1, -1, 0);
  FOR(i, 1, n + 1) {
    printf("%d%c", dp[i] + dp2[i], " \n"[i == n]);
  }
  return 0;
}
