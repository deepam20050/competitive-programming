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

vector < int > g[N];
int d[2][N];

pii dfs (int u, int p, int depth, int who = -1) {
  if (who != -1) {
    d[who][u] = depth;
  }
  pii ret = {depth, u};
  for (auto &to : g[u]) {
    if (to != p) {
      ret = max(ret, dfs(to, u, depth + 1, who));
    }
  }
  return ret;
}

void test_case() {
  int n; cin >> n;
  for (int i = 1; i < n; ++i) {
    int a, b; cin >> a >> b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  auto phase1 = dfs(1, 0, 0, -1);
  auto phase2 = dfs(phase1.second, 0, 0, 0);
  auto phase3 = dfs(phase2.second, 0, 0, 1);
  for (int i = 1; i <= n; ++i) {
    cout << max(d[0][i], d[1][i]) << " ";
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