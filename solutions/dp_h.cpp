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

const int N = 1005;
const int MOD = 1e9 + 7;

int dp[N][N];
string s[N];

int add (int x, int y) {
  x += y;
  return x >= MOD ? x -= MOD : x;
}

void test_case() {
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  dp[n - 1][m - 1] = 1;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      if (i == n - 1 && j == m - 1) continue;
      dp[i][j] = add(dp[i + 1][j] * (s[i][j] == '.'), dp[i][j + 1] * (s[i][j] == '.'));
    }
  }
  cout << dp[0][0] << '\n';
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