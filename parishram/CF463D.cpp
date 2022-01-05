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

const int N = 1005;

int arr[N];
int edge[N][N];
bool used[N];
int dp[N];
vector < int > g[N];

int ans;

void dfs (int u) {
  used[u] = 1;
  for (auto &to : g[u]) {
    if (!used[to]) {
      dfs(to);
    }
    dp[u] = max(dp[u], dp[to] + 1);
  }
  dp[u] = max(dp[u], 1);
  ans = max(ans, dp[u]);
}

int main () {
  int n, kk;
  scanf("%d %d", &n, &kk);
  FOR(i, 0, kk) {
    FOR(j, 0, n) scanf("%d", arr + j), --arr[j];
    FOR(j, 0, n) FOR(k, j + 1, n) {
      ++edge[arr[j]][arr[k]];
    }
  }
  FOR(i, 0, n) FOR(j, 0, n) {
    if (edge[i][j] == kk) {
      g[i].eb(j);
    }
  }
  FOR(i, 0, n) {
    memset(used, 0, sizeof used);
    dfs(i);
  }
  printf("%d\n", ans);
  return 0;
}
