const int N = 4e4 + 2;
const int LN = 20;

vector < int > g[N];
int tin[N];
int tout[N];
int timer;
int up[N][LN];
int m;

void dfs (int u, int p) {
  tin[u] = ++timer;
  up[u][0] = p;
  for (int i = 1; i < LN; ++i) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  for (auto &to : g[u]) {
    if (to != p) {
      dfs(to, u);
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