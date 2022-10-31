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

using lli = int64_t;
using pii = pair < int, int >;

const int N = 205;

int a[N][N];
int n, m;
const int dx[] = {1, -1, -1, 1};
const int dy[] = {1, 1, -1, -1};

inline bool check (int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

void test_case() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int curr = a[i][j];
      for (int z = 0; z < 4; ++z) {
        int x = i + dx[z], y = j + dy[z];
        while (check(x, y)) {
          curr += a[x][y];
          x += dx[z];
          y += dy[z];
        }
      }
      ans = max(ans, curr);
    }
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