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

int up[N][LN];
vector < int > g[N];
int timer;
int tin[N];
int tout[N];
int d[N];

void dfs (int u, int p) {
  tin[u] = ++timer;
  up[u][0] = p;
  for (int i = 1; i < LN; ++i) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  for (auto &to : g[u]) {
    if (to != p) {
      d[to] = d[u] + 1;
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

int dist (int a, int b) {
  return d[a] + d[b] - 2 * d[lca(a, b)] + 1;
}

int solve (int s, int f, int t) {
  if (is_ancestor(f, s) ^ is_ancestor(f, t)) {
    return 1;
  }
  if (is_ancestor(f, s) && is_ancestor(f, t)) {
    return dist(f, lca(s, t));
  }
  int tmp1 = lca(f, s);
  int tmp2 = lca(f, t);
  if (tmp1 == tmp2) {
    return dist(f, lca(s, t));
  }
  return d[f] - max(d[tmp1], d[tmp2]) + 1;
}

void test_case() {
  int n, nq; cin >> n >> nq;
  for (int i = 2; i <= n; ++i) {
    int p; cin >> p;
    g[i].emplace_back(p);
    g[p].emplace_back(i);
  }
  dfs(1, 1);
  debug(lca(1, 3));
  debug(lca(3, 3));
  while (nq--) {
    array < int, 3 > a;
    cin >> a[0] >> a[1] >> a[2];
    int ans = 0;
    sort(all(a));
    do {
      ans = max(ans, solve(a[0], a[1], a[2]));
    } while (next_permutation(all(a)));
    cout << ans << '\n';
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