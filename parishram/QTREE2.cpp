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

const int N = 1e4 + 5;
const int LN = 14;

vector < pii > g[N];
int timer;
int tin[N];
int tout[N];
int up[N][LN];
int d[N];
lli dist[N];

void dfs (int u, int p) {
  tin[u] = ++timer;
  up[u][0] = p;
  for (int i = 1; i < LN; ++i) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  for (auto [to, w] : g[u]) {
    if (to != p) {
      d[to] = d[u] + 1;
      dist[to] = dist[u] + w;
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

int find_kth (int u, int d) {
  for (int i = 0; i < LN; ++i) {
    if (d >> i & 1) {
      u = up[u][i];
    }
  }
  return u;
}

void test_case() {
  int n; cin >> n;
  timer = 0;
  for (int i = 1; i <= n; ++i) {
    g[i].clear();
    d[i] = 0;
    dist[i] = 0;
    for (int j = 0; j < LN; ++j) {
      up[i][j] = 0; 
    }
  }
  for (int i = 1; i < n; ++i) {
    int a, b, c; cin >> a >> b >> c;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }
  dfs(1, 1);
  string s; 
  while (cin >> s && s[1] != 'O') {
    if (s[0] == 'D') {
      int a, b; cin >> a >> b;
      int w = lca(a, b);
      cout << dist[a] - dist[w] + dist[b] - dist[w] << '\n';
    } else {
      int a, b, k; cin >> a >> b >> k;
      int w = lca(a, b);
      --k;
      if (d[a] - d[w] >= k) {
        cout << find_kth(a, k) << '\n';
      } else {
        cout << find_kth(b, d[b] - d[w] - (k - (d[a] - d[w]))) << '\n';
      }
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}