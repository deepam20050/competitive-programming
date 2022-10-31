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

const int N = 105;

bool used[N][N];
int n, m, sx, sy;

void test_case() {
  cin >> n >> m >> sx >> sy;
  cout << sx << " " << sy << '\n';
  cout << 1 << " " << sy << '\n';
  cout << 1 << " " << 1 << '\n';
  used[sx][sy] = used[1][sy] = used[1][1] = 1;
  for (int i = 1; i <= n; ++i) {
    if (i & 1) {
      for (int j = 1; j <= m; ++j) {
        if (!used[i][j]) {
          cout << i << " " << j << '\n';
          used[i][j] = 1;
        }
      }
    } else {
      for (int j = m; j >= 1; --j) {
        if (!used[i][j]) {
          cout << i << " " << j << '\n';
          used[i][j] = 1;
        }
      }
    }
  }
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