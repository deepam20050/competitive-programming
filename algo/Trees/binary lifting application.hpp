const int N = 1e5 + 5;
const int LN = 19;

vector < pii > g[N];
int timer;
int tin[N];
int tout[N];
int up[N][LN], max_edge[N][LN], min_edge[N][LN];
int d[N];

void dfs (int u, int p, int e) {
  tin[u] = ++timer;
  up[u][0] = p;
  if (u != 1) {
    max_edge[u][0] = e;
    min_edge[u][0] = e;
  } else {
    max_edge[u][0] = 0;
    min_edge[u][0] = 2e9;
  }
  for (int i = 1; i < LN; ++i) {
    up[u][i] = up[up[u][i - 1]][i - 1];
    max_edge[u][i] = max(max_edge[u][i - 1], max_edge[up[u][i - 1]][i - 1]);
    min_edge[u][i] = min(min_edge[u][i - 1], min_edge[up[u][i - 1]][i - 1]);
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

int get_min (int u, int d) {
  int ret = 2e9;
  for (int i = LN - 1; i >= 0; --i) {
    if (d >> i & 1) {
      ret = min(ret, min_edge[u][i]);
      u = up[u][i];
    }
  }
  return ret;
}