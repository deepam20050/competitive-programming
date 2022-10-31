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

const int N = 3000;

double dp[N][N];

void test_case() {
  int n; cin >> n;
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    double p; cin >> p;
    for (int heads = 0; heads <= n; ++heads) {
      int tails = n - heads;
      if (heads > 0) {
        dp[i][heads] += p * dp[i - 1][heads - 1];
      } 
      if (tails > 0) {
        dp[i][heads] += (1.0 - p) * dp[i - 1][heads];
      }
    }
  }
  double ans = 0;
  for (int heads = 1; heads <= n; ++heads) {
    int tails = n - heads;
    if (heads > tails) {
      ans += dp[n][heads];
    }
  }
  cout << fixed << setprecision(10);
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