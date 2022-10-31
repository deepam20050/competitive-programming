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

const int N = 18;

lli dp[1 << N][N];
lli c[N];
lli extra[N][N];

void test_case() {
  int n, m, k; cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  for (int i = 0; i < k; ++i) {
    int x, y, c; cin >> x >> y >> c;
    extra[x - 1][y - 1] = c;
  }
  lli ans = 0;
  for (int mask = 1; mask < (1 << n); ++mask) {
    bool ok = __builtin_popcount(mask) == m;
    for (int i = 0; i < n; ++i) {
      if (mask >> i & 1) {
        dp[mask][i] = c[i];
        for (int j = 0; j < n; ++j) {
          if (i != j && (mask >> j & 1)) {
            dp[mask][i] = max(dp[mask][i], dp[mask ^ (1 << i)][j] + extra[j][i] + c[i]);
          }
        }
      }
      if (ok) {
        ans = max(ans, dp[mask][i]);
      }
    }
  }
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