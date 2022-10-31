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

const int N = 1e5 + 5;

vector < int > g[N];
int n, a, b, da, db;
int dist[N];

void dfs (int u, int p) {
  for (auto &to : g[u]) {
    if (to != p) {
      dist[to] = dist[u] + 1;
      dfs(to, u);
    }
  }
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d %d %d %d %d", &n, &a, &b, &da, &db);
    FOR(i, 1, n + 1) g[i].clear();
    FOR(i, 1, n) {
      int x, y;
      scanf("%d %d", &x, &y);
      g[x].eb(y);
      g[y].eb(x);
    }
    dist[a] = 0;
    dfs(a, 0);
    if (dist[b] <= da) {
      puts("Alice");
      continue;
    }
    int u = max_element(dist, dist + n + 1) - dist;
    dist[u] = 0;
    dfs(u, 0);
    int diam = *max_element(dist, dist + n + 1);
    if (diam <= 2 * da) {
      puts("Alice");
      continue;
    }
    if (db > 2 * da) puts("Bob");
    if (db <= 2 * da) puts("Alice");
  }
  return 0;
}
