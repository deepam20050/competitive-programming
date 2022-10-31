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

int dp[N][3];
int score[N][3];

void test_case() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> score[i][j];
    }
  }
  for (int i = n; i >= 1; --i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (j != k) {
          dp[i][j] = max(dp[i][j], dp[i + 1][k]);
        }
      }
      dp[i][j] += score[i][j];
    }
  }
  cout << max({dp[1][0], dp[1][1], dp[1][2]}) << '\n';
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