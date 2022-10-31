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

const int N = 1002;

int a[N][N];
int n, m;
bool dp[N][N][2][2];

bool check (int x, int y) {
  return 1 <= x && x <= n && 1 <= y && y <= m;
}

// 0 -> 1
// 1 -> -1
void solve (int x, int y, int x0, int y0) {
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (a[x][y] == -1) {
        dp[x][y][i][j] |= dp[x0][y0][i][j ^ 1];
      } else {
        dp[x][y][i][j] |= dp[x0][y0][i ^ 1][j];
      }
    }
  }
}

void test_case() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      for (int x = 0; x < 2; ++x) {
        for (int y = 0; y < 2; ++y) {
          dp[i][j][x][y] = 0;
        }
      }
    }
  }
  if (a[1][1] == 1) {
    dp[1][1][1][0] = 1;
  } else {
    dp[1][1][0][1] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (i == 1 && j == 1) continue;
      int x = i - 1, y = j;
      if (check(x, y)) {
        solve(i, j, x, y);
      }
      x = i;
      y = j - 1;
      if (check(x, y)) {
        solve(i, j, x, y);
      }
    }
  } 
  bool ok = 0;
  for (int i = 0; i < 2; ++i) {
    ok |= dp[n][m][i][i];
    if (dp[n][m][i][i]) {
      cout << i << '\n';
    }
  }
  ok ? cout << "YES\n" : cout << "NO\n";
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