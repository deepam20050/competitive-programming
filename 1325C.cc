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
int ans[N];

void test_case() {
  memset(ans, -1, sizeof ans);
  int n; cin >> n;
  for (int i = 0; i + 1 < n; ++i) {
    int x, y; cin >> x >> y;
    g[x].emplace_back(i);
    g[y].emplace_back(i);
  }
  int val = 0;
  for (int i = 1; i <= n; ++i) {
    if (sz(g[i]) >= 3) {
      for (auto &pos : g[i]) {
        if (ans[pos] == -1) {
          ans[pos] = val++;
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (auto &pos : g[i]) {
      if (ans[pos] == -1) {
        ans[pos] = val++;
      }
    }
  }
  for (int i = 0; i + 1 < n; ++i) {
    cout << ans[i] << '\n';
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