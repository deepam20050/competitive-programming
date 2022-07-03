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
lli dp[N];

void test_case() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    ++a[x];
  }
  for (int x = N - 5; x >= 1; --x) {
    dp[x] = max(dp[x + 1], a[x] * 1ll * x + dp[x + 2]);
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