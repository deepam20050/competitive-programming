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

vector < pii > g[N];
lli d[N];
bool bad[N];
int a[N];
int subtree[N];
multiset < lli > mini;

int dfs (int u, int p) {
  if (!mini.empty() && *mini.begin() < d[u] - a[u]) {
    bad[u] = 1;
  }
  mini.emplace(d[u]);
  for (auto [to, w] : g[u]) {
    if (to != p) {
      d[to] = d[u] + w;
      subtree[u] += dfs(to, u);
    }
  }
  mini.erase(mini.lower_bound(d[u]));
  return subtree[u] += 1;
}

int ans;

void dfs2 (int u, int p) {
  if (bad[u]) {
    ans += subtree[u];
    return;
  }
  for (auto [to, ignore] : g[u]) {
    if (to != p) {
      dfs2(to, u);
    }
  }
}

void test_case() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i < n; ++i) {
    int x, y; cin >> x >> y;
    g[i + 1].emplace_back(x, y);
    g[x].emplace_back(i + 1, y);
  }
  dfs(1, 1);
  dfs2(1, 1);
  cout << ans << '\n';
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