#include "bits/stdc++.h"

using namespace std;

const int N = 2005;
const int MOD = 1e9 + 7;

vector < int > g[N];
bitset < N > vis;
int f[N];
int n, d;
int a[N];

void dfs (int u, int root) {
  vis[u] = 1;
  f[u] = 1;
  for (int &to : g[u]) {
    if (vis[to]) continue;
    if (a[root] <= a[to] && a[to] <= a[root] + d) {
      if (a[root] == a[to] && to < root) {
        continue;
      }
      dfs(to, root);
      f[u] = 1ll * f[u] * (f[to] + 1) % MOD;
    }
  }
}

int main () {
  scanf("%d %d", &d, &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      vis[j] = 0;
      f[j] = 0;
    }
    dfs(i, i);
    ans = (ans + f[i]) % MOD;
  }
  printf("%d\n", ans);
  return 0;
}
