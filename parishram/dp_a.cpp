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

int dp[N];
int a[N];

void test_case() {
  int n; cin >> n;
  fill(dp + 1, dp + n + 1, (int)2e9);
  dp[n] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = n - 1; i >= 1; --i) {
    if (i + 1 <= n) {
      dp[i] = min(dp[i], abs(a[i] - a[i + 1]) + dp[i + 1]);
    }
    if (i + 2 <= n) {
      dp[i] = min(dp[i], abs(a[i] - a[i + 2]) + dp[i + 2]);
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