#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 5;
const int neg_inf = -1;

bitset < N > vis;
queue < int > q;
int sp[N];
vector < int > g[N];
int dist[2][N];

void bfs (int node, int who) {
  vis.reset();
  vis[node] = 1;
  dist[who][node] = 0;
  q.emplace(node);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int &to : g[u]) {
      if (!vis[to]) {
        vis[to] = 1;
        dist[who][to] = dist[who][u] + 1;
        q.emplace(to);
      }
    }
  }
}

int main () {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= k; ++i) {
    scanf("%d", sp + i);
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  fill(dist[0], dist[0] + N, 1 << 29);
  fill(dist[1], dist[1] + N, 1 << 29);
  bfs(1, 0);
  bfs(n, 1);
  sort(sp + 1, sp + k + 1, [&] (const int &a, const int &b) {
    return dist[0][a] - dist[1][a] < dist[0][b] - dist[1][b];
  });
  int ans = -1e9;
  int curr_mx = -1e9;
  for (int i = 1; i <= k; ++i) {
    ans = max(ans, 1 + dist[1][sp[i]] + curr_mx);
    curr_mx = max(curr_mx, dist[0][sp[i]]);
  }
  printf("%d\n", min(ans, dist[0][n]));
  return 0;
} 
