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

const int N = 105;
const int W = 1e5 + 2;
const lli inf = 1e18;

lli dp[N][W];
int w[N];
lli v[N];

void test_case() {
  int n, weight; cin >> n >> weight;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i] >> v[i];
    fill(dp[i], dp[i] + W, -inf);
  }
  dp[0][0] = 0;
  lli ans = -inf;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= weight; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j >= w[i]) {
        dp[i][j] = max(dp[i][j], v[i] + dp[i - 1][j - w[i]]);
      }
      ans = max(ans, dp[i][j]);
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