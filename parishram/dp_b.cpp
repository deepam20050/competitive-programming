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

int a[N];
int dp[N];

void test_case() {
  int n, k; cin >> n >> k;
  fill(dp, dp + n + 1, (int)2e9);
  dp[n] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = n - 1; i >= 1; --i) {
    for (int j = 1; j <= k && i + j <= n; ++j) {
      dp[i] = min(dp[i], abs(a[i] - a[i + j]) + dp[i + j]);
    }
  }
  cout << dp[1] << '\n';
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