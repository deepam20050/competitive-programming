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
const int LN = 17;

vector < int > g[N];
vector < int > state[N];
vector < pii > queries[N];
int d[N];
int up[N][LN];
int level[N];
int ans[N];

void dfs (int u, int p) {
  up[u][0] = p;
  for (int i = 1; i < LN; ++i) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  for (auto &to : g[u]) {
    d[to] = d[u] + 1;
    dfs(to, u);
  }
}

int find_kth (int u, int k) {
  for (int i = 0; i < LN; ++i) {
    if (k >> i & 1) {
      u = up[u][i];
    }
  }
  return u;
}

void dfs2 (int u) {
  for (auto [p, ignore] : queries[u]) {
    state[u].emplace_back(level[p + d[u]]);
  }
  level[d[u]] += 1;
  for (auto &to : g[u]) {
    dfs2(to);
  }
  for (int i = 0; i < sz(queries[u]); ++i) {
    auto [p, idx] = queries[u][i];
    ans[idx] = level[p + d[u]] - state[u][i] - 1;
  }
}

void test_case() {
  int n; cin >> n;
  vector < int > roots;
  for (int i = 1; i <= n; ++i) {
    int p; cin >> p;
    if (p == 0) {
      roots.emplace_back(i);
    } else {
      g[p].emplace_back(i);
    }
  }
  for (auto &r : roots) {
    dfs(r, r);
  }
  int nq; cin >> nq;
  for (int i = 0; i < nq; ++i) {
    int v, p; cin >> v >> p;
    int w = find_kth(v, p);
    if (d[v] - d[w] == p) {
      queries[w].emplace_back(p, i);
    }
  }
  for (auto &r : roots) {
    dfs2(r);
  }
  for (int i = 0; i < nq; ++i) {
    cout << ans[i] << " ";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}