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
int ans[N];

void test_case() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i + 1 < n; ++i) {
    int x, y; cin >> x >> y;
    g[x].emplace_back(y, i);
    g[y].emplace_back(x, i);
  }
  for (int i = 1; i <= n; ++i) {
    if (sz(g[i]) > 2) {
      cout << -1 << '\n';
      return;
    }
  }
  int curr = 2;
  function < void (int, int) > dfs = [&] (int u, int p) {
    for (auto [to, idx] : g[u]) {
      if (to != p) {
        ans[idx] = curr;
        curr = 5 - curr;
        dfs(to, u);
      }
    }
  };
  for (int i = 1; i <= n; ++i) {
    if (sz(g[i]) == 1) {
      dfs(i, 0);
      break;
    }
  }
  for (int i = 0; i + 1 < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}

int main() {
  #ifdef DEBUG
  freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}
