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

void test_case() {
  int n; cin >> n;
  vector < vector < int > > a(2, vector < int > (n, -1));
  for (int i = 0; i < 2; ++i) {
    string s; cin >> s;
    for (int j = 0; j < n; ++j) {
      a[i][j] = s[j] - '0';
    }
  }
  vector < int > dp(n + 1);
  for (int i = n - 1; i >= 0; --i) {
    bool used[2] = {};
    used[a[0][i]] = used[a[1][i]] = 1;
    int x = 0;
    while (x < 2 && used[x]) {
      ++x;
    }
    dp[i] = x + dp[i + 1];
    if (i + 1 < n) {
      used[a[0][i + 1]] = used[a[1][i + 1]] = 1;
      x = 0;
      while (x < 2 && used[x]) {
        ++x;
      }
      dp[i] = max(dp[i], x + dp[i + 2]);
    }
  }
  cout << dp[0] << '\n';
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}