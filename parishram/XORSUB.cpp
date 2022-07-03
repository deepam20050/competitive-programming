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

const int M = 1024;

int dp[2][M];

void test_case() {
  memset(dp, 0, sizeof dp);
  int n, k; cin >> n >> k;
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    dp[i & 1][0] = 1;
    for (int j = 1; j < M; ++j) {
      dp[i & 1][j] |= dp[(i & 1) ^ 1][j ^ x] | dp[(i & 1) ^ 1][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < M; ++i) {
    ans = max(ans, dp[n & 1][i] ? (i ^ k) : 0);
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