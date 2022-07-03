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

const int N = 21;
const int MOD = 1e9 + 7;

int dp[1 << N];
int compat[N][N];

int add (int a, int b) {
  a += b;
  return a >= MOD ? a -= MOD : a;
}

void test_case() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> compat[i][j];
    }
  }
  dp[0] = 1;
  for (int mask = 0; mask < (1 << n); ++mask) {
    int guy = __builtin_popcount(mask);
    for (int w = 0; w < n; ++w) {
      if ((mask >> w & 1) || !compat[guy][w]) continue;
      dp[mask ^ (1 << w)] = add(dp[mask ^ (1 << w)], dp[mask]);
    }
  }
  cout << dp[(1 << n) - 1] << '\n';
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