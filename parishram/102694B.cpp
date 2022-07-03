// AC
#include "bits/stdc++.h"

using namespace std;

const int N = 3e5 + 5;

vector < int > g[N];
int dist[N][2];
bitset < N > vis, endpoint;
queue < int > q;

int bfs (int x, int who) {
  vis.reset();
  vis[x] = 1;
  q.emplace(x);
  int node = 0;
  int len = -1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (dist[u][who] > len) {
      node = u;
      len = dist[u][who];
    }
    for (int &to : g[u]) {
      if (!vis[to]) {
        dist[to][who] = dist[u][who] + 1;
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
  int farthest = bfs(1, 0);
  bfs(farthest, 1);
  int mx_dist = 0;
  int dia = 0;
  for (int i = 1; i <= n; ++i) {
    mx_dist = max(mx_dist, dist[i][0]);
    dia = max(dia, dist[i][1]);
  }
  if (mx_dist == dia) {
    endpoint[1] = 1;
  }
  for (int i = 2; i <= n; ++i) {
    endpoint[i] = (dist[i][0] == mx_dist || dia == dist[i][1]);
  }
  for (int i = 1; i <= n; ++i) {
    if (endpoint[i]) {
      printf("%d\n", dia + 1);
    } else {
      printf("%d\n", dia);
    }
  }
  return 0;
}