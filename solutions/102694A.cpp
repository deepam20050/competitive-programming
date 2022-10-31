// AC
#include "bits/stdc++.h"

using namespace std;

const int N = 3e5 + 5;

vector < int > g[N];
int dist[N];
bitset < N > vis;
queue < int > q;

int bfs (int x) {
  memset(dist, 0, sizeof dist);
  vis.reset();
  vis[x] = 1;
  q.emplace(x);
  int node = 0;
  int len = -1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (dist[u] > len) {
      node = u;
      len = dist[u];
    }
    for (int &to : g[u]) {
      if (!vis[to]) {
        dist[to] = dist[u] + 1;
        vis[to] = 1;
        q.emplace(to);
      }
    }
  }
  return node;
}

int main () {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  int farthest = bfs(1);
  bfs(farthest);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, dist[i]);
  }
  printf("%d\n", ans * 3);
  return 0;
}