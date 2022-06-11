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

const int N = 3e5 + 5;

vector < int > g[N];
int subtree[N];
int n;
int dp[N];

int dfs (int u, int p) {
  for (auto &to : g[u]) {
    if (to == p) continue;
    subtree[u] += dfs(to, u) + 1;
  }
  return subtree[u];
}

int solve (int u, int p) {
  vector < int > kids;
  for (auto &to : g[u]) {
    if (to != p) {
      kids.emplace_back(to);
    }
  }
  if (kids.empty()) {
    return 0;
  }
  if (sz(kids) == 1) {
    dp[u] = subtree[kids.back()];
  } else {
    for (int i = 0; i < 2; ++i) {
      int to = kids[i];
      dp[u] = max({dp[u], solve(to, u) + subtree[kids[i ^ 1]]});
    }
  }
  return dp[u];
}

void test_case() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    subtree[i] = 0;
    dp[i] = 0;
    g[i].clear();
  }
  for (int i = 1; i < n; ++i) {
    int a, b; cin >> a >> b;
    --a; --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  dfs(0, -1);
  cout << solve(0, -1) << '\n';
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