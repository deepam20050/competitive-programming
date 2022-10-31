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

const int N = 2e5 + 5;
const int LN = 20;

int tin[N];
int tout[N];
int timer;
int up[N][LN];
vector < int > g[N];

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

void test_case() {
  int n; cin >> n;
  for (int i = 1; i < n; ++i) {
    int x, y; cin >> x >> y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  dfs(1, 1);
  int nq; cin >> nq;
  while (nq--) {
    int k; cin >> k;
    vector < int > nodes(k);
    for (auto &e : nodes) {
      cin >> e;
    }
    sort(all(nodes), [&] (int u, int v) {
      return tin[u] < tin[v];
    });
    if (k == 1) {
      cout << "YES\n";
      continue;
    }
    int w = nodes[0];
    for (auto &e : nodes) {
      w = lca(w, e);
    }
    if (nodes[0] == w) {
      nodes.erase(nodes.begin());
      --k;
    }
    int branches = 0;
    bool ok = 1;
    for (int i = 1; i < k; ++i) {
      if (!is_ancestor(nodes[i - 1], nodes[i])) {
        ok &= lca(nodes[i - 1], nodes[i]) == w;
        ++branches;
      }
    }
    ok && branches <= 1 ? cout << "YES\n" : cout << "NO\n";
  }
}

int main() {
  #ifdef DEBUG
  freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}
