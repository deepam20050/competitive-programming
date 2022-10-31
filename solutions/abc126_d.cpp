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
int color[N];

void dfs (int u, int p) {
  for (auto &[to, w] : g[u]) {
    if (to == p) continue;
    if (!w) {
      color[to] = color[u];
      dfs(to, u);
    } else {
      color[to] = color[u] ^ 1;
      dfs(to, u);
    }
  }
}

void test_case() {
  int n; cin >> n;
  for (int i = 1; i < n; ++i) {
    int x, y, w; cin >> x >> y >> w;
    g[x].emplace_back(y, w & 1);
    g[y].emplace_back(x, w & 1);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; ++i) {
    cout << color[i] << '\n';
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
