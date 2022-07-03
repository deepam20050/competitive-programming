#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
  #include "../algo/debug.hpp"
#else
  #define debug(...)
#endif
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back

using lli = long long;
using pii = pair < int, int >;

const int N = 1e5 + 5;
const int LN = 19;

vector < pii > g[N];
int timer;
int tin[N];
int tout[N];
int up[N][LN], max_edge[N][LN];
int d[N];

void dfs (int u, int p, int e) {
  tin[u] = ++timer;
  up[u][0] = p;
  max_edge[u][0] = e;
  for (int i = 1; i < LN; ++i) {
    up[u][i] = up[up[u][i - 1]][i - 1];
    max_edge[u][i] = max(max_edge[u][i - 1], max_edge[up[u][i - 1]][i - 1]);
  }
  for (auto [to, w] : g[u]) {
    if (to != p) {
      d[to] = d[u] + 1;
      dfs(to, u, w);
    }
  }
  tout[u] = ++timer;
}

bool is_ancestor (int u, int v) {
  return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca (int u, int v) {
  if (is_ancestor(u, v)) return u;
  if (is_ancestor(v, u)) return v;
  for (int i = LN - 1; i >= 0; --i) {
    if (!is_ancestor(up[u][i], v)) {
      u = up[u][i];
    }
  }
  return up[u][0];
}

int get_max (int u, int d) {
  int ret = 0;
  for (int i = LN - 1; i >= 0; --i) {
    if (d >> i & 1) {
      ret = max(ret, max_edge[u][i]);
      u = up[u][i];
    }
  }
  return ret;
}

void test_case() {
  int n; cin >> n;
  if (!n) {
    exit(0);
  }
  timer = 0;
  for (int i = 1; i <= n; ++i) {
    g[i].clear();
  }
  for (int i = 1; i < n; ++i) {
    int a, b, c; cin >> a >> b >> c;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }
  dfs(1, 1, 0);
  int nq; cin >> nq;
  while (nq--) {
    int x, y; cin >> x >> y;
    int w = lca(x, y);
    int max_ans = max(get_max(x, d[x] - d[w]), get_max(y, d[y] - d[w]));
    cout << max_ans << '\n';
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  while (true) {
    test_case();
  }
  return 0;
}