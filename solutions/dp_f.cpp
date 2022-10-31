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

const int N = 3002;

string s, t;
int dp[N][N];

void test_case() {
  cin >> s >> t;
  int n = sz(s), m = sz(t);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  string ans;
  int i = n, j = m;
  while (i > 0 && j > 0) {
    if (s[i - 1] == t[j - 1]) {
      ans += s[i - 1];
      --i;
      --j;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      --i;
    } else {
      --j;
    }
  }
  reverse(all(ans));
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