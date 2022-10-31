#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 5;

bitset < N > vis;
queue < int > q;
vector < int > g[N];
int d[N], dp[N];

void calc_ds () {
  d[1] = 0;
  vis[1] = 1;
  q.emplace(1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int &v : g[u]) {
      if (!vis[v]) {
        vis[v] = 1;
        d[v] = d[u] + 1;
        q.emplace(v);
      }
    }
  }
}

void optimize (int u) {
  vis[u] = 1;
  for (int &v : g[u]) {
    if (!vis[v] && d[v] > d[u]) {
      optimize(v);
    }
    if (d[v] > d[u]) {
      dp[u] = min(dp[u], dp[v]);
    } else {
      dp[u] = min(dp[u], d[v]);
    }
  }
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
      vis[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      g[x].emplace_back(y);
    }
    calc_ds();
    for (int i = 1; i <= n; ++i) {
      dp[i] = d[i];
    }
    vis.reset();
    optimize(1);
    for (int i = 1; i <= n; ++i) {
      printf("%d ", dp[i]);
    }
    puts("");
  }
  return 0;
}
