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

const int V = 1e5 + 5;
const int N = 102; 
const lli inf = 4e18;

lli dp[N][V];

void test_case() {
  int n, w; cin >> n >> w;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < V; ++j) {
      dp[i][j] = inf;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    int w, v; cin >> w >> v;
    for (int j = 0; j < V; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (v <= j) {
        dp[i][j] = min(dp[i][j], w + dp[i - 1][j - v]);
      }
    }
  }
  int ans = 0;
  for (int i = V - 1; i >= 0; --i) {
    if (dp[n][i] <= w) {
      ans = i;
      break;
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