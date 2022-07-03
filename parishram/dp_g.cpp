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

vector < int > g[N];
int dp[N];
int indeg[N];
bool used[N];

void dfs (int u) {
  used[u] = 1;
  for (auto &to : g[u]) {
    if (!used[to]) {
      dfs(to);
    }
    dp[u] = max(dp[u], dp[to]);
  }
  dp[u] += !g[u].empty();
  return;
}

void test_case() {
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b;
    g[a].emplace_back(b);
    ++indeg[b];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (!indeg[i]) {
      dfs(i);
    }
  }
  cout << *max_element(dp, dp + n + 1) << '\n';
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