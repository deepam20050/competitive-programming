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
bool used[N];

int dfs (int u, int p) {
  used[u] = 1;
  for (auto &to : g[u]) {
    if (to != p && !used[to]) {
      return dfs(to, u) + 1;
    }
  }
  return 1;
}

void test_case() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    g[i].clear();
    used[i] = 0;
  }
  bool no = 0;
  for (int i = 1; i <= n; ++i) {
    int a, b; cin >> a >> b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
    if (sz(g[a]) > 2 || sz(g[b]) > 2 || a == b) {
      no = 1;
    }
  }
  if (no) {
    cout << "NO\n";
    return;
  }
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) {
      if (dfs(i, 0) & 1) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
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
