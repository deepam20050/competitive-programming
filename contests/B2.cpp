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

const int N = 2e5 + 5;

lli dp[N];

void test_case() {
  int n; cin >> n;
  string s; cin >> s;
  lli ans = 0;
  fill(dp, dp + n + 1, 0);
  int pos_1 = n + 1, pos_0 = n + 1;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '1') {
      dp[i] = 1;
      if (pos_1 != n + 1) {
        dp[i] += (pos_1 - 1 == i ? dp[pos_1] - 1 : dp[pos_1] + 1);
      } else {
        dp[i] += i + 1 == n ? 0 : 1;
      }
      pos_1 = i;
    } else {
      dp[i] = 1;
      if (pos_0 != n + 1) {
        dp[i] += (pos_0 - 1 == i ? dp[pos_0] - 1 : dp[pos_0] + 1);
      } else {
        dp[i] += i + 1 == n ? 0 : 1;
      }
      pos_0 = i;
    }
    ans += dp[i];
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