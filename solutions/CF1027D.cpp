#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 5;

int to[N], c[N], vis[N];
int ans;
vector < pair < int, int > > cycle;

void dfs (int node) {
  vis[node] = 1;
  if (to[node] == node) {
    ans += c[node];
  } else {
    if (!vis[to[node]]) {
      dfs(to[node]);
    } else if (vis[to[node]] == 1) {
      cycle.emplace_back(to[node], node);
    } 
  }
  vis[node] = 2;
}

int dfs2 (int strt, int finish) {
  vis[strt] = 1;
  int mini = c[strt];
  if (strt == finish) {
    return mini;
  }
  return min(mini, dfs2(to[strt], finish));
}

int main () {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &c[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", to + i);
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  memset(vis, 0, sizeof vis);
  for (auto &pi : cycle) {
    int strt = pi.first, finish = pi.second;
    ans += dfs2(strt, finish);
  }
  printf("%d\n", ans);
  return 0;
}
