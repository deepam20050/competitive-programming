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
vector < int > level[N];
int d[N];
int up[N][LN];
int timer;
int tin[N];
int tout[N];

void dfs (int u, int p) {
  tin[u] = ++timer;
  up[u][0] = p;
  for (int i = 1; i < LN; ++i) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  level[d[u]].emplace_back(tin[u]);
  for (auto &to : g[u]) {
    d[to] = d[u] + 1;
    dfs(to, u);
  }
  tout[u] = ++timer;
}

int find_kth (int u, int k) {
  for (int i = 0; i < LN; ++i) {
    if (k >> i & 1) {
      u = up[u][i];
    }
  }
  return u;
}

int solve (int u, int p) {
  return upper_bound(all(level[p]), tout[u]) - lower_bound(all(level[p]), tin[u]) - 1;
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
  for (int i = 0; i <= n; ++i) {
    sort(all(level[i]));
  }
  int nq; cin >> nq;
  for (int i = 0; i < nq; ++i) {
    int v, p; cin >> v >> p;
    int w = find_kth(v, p);
    if (d[v] - d[w] == p) {
      cout << solve(w, d[w] + p) << " ";
    } else {
      cout << 0 << " ";
    }
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