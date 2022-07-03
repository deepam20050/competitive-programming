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

const int N = 4005;

int dp[N];
int n;

void test_case() {
  cin >> n;
  array < int, 3 > a;
  for (auto &e : a) {
    cin >> e;
  }
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (auto &j : a) {
      if (i - j >= 0 && dp[i - j]) {
        dp[i] = max(dp[i], dp[i - j] + 1);
      }
    }
  }
  cout << dp[n] - 1 << '\n';
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