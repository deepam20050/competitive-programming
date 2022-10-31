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
const int LN = 18;

int up[N][LN];
int tin[N];
int tout[N];
int timer;
int sum[N];
int n;
vector < int > g[N];
pii edge[N];

void dfs (int u, int p = -1) {
  tin[u] = ++timer;
  FOR(i, 1, LN) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  for (auto to : g[u]) {
    if (to != p) {
      up[to][0] = u;
      dfs(to, u);
    }
  }
  tout[u] = ++timer;
}

inline bool is_ancestor (int a, int b) {
  return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int get_lca (int a, int b) {
  if (is_ancestor(a, b)) return a;
  if (is_ancestor(b, a)) return b;
  for (int i = LN - 1; i >= 0; --i) {
    if (!is_ancestor(up[a][i], b)) {
      a = up[a][i];
    }
  }
  return up[a][0];
}


int dfs2 (int u, int p) {
  for (auto to : g[u]) {
    if (to != p) {
      sum[u] += dfs2(to, u);
    }
  }
  return sum[u];
}

int main () {
  scanf("%d", &n);
  FOR(i, 0, n - 1) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].eb(b);
    g[b].eb(a);
    edge[i] = {a, b};
  }
  up[1][0] = 1;
  dfs(1);
  int nq;
  scanf("%d", &nq);
  while (nq--) {
    int a, b;
    scanf("%d %d", &a, &b);
    int lca = get_lca(a, b);
    sum[lca] -= 2;
    ++sum[a];
    ++sum[b];
  }
  dfs2(1, 1);
  FOR(i, 0, n - 1) {
    auto [a, b] = edge[i];
    if (is_ancestor(a, b)) swap(a, b);
    printf("%d ", sum[a]);
  }
  return 0;
}
