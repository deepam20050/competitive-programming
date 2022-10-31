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

using lli = int64_t;
using pii = pair < int, int >;

const int N = 4e5 + 5;
const int MOD = 1e9 + 7;

bool used[2][N];
int a[2][N];
int c[N];
int n;
vector < pii > g[N];

void dfs (int idx, int u) {
  used[idx][u] = 1;
  int x = a[idx ^ 1][u];
  if (used[idx ^ 1][u]) return;
  used[idx ^ 1][u] = 1;
  for (auto [to_idx, pos] : g[x]) {
    if (!used[to_idx][pos]) {
      dfs(to_idx, pos);
    }
  }
}

void test_case() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    used[0][i] = used[1][i] = 0;
    g[i + 1].clear();
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      g[a[i][j]].emplace_back(i, j);
    }
  }
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (!used[j][i]) {
        dfs(j, i);
        if (a[j][i] != a[j ^ 1][i]) {
          ans += ans;
        }
        if (ans >= MOD) {
          ans -= MOD;
        }
      }
    }
  }
  cout << ans << '\n';
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