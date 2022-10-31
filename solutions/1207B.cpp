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

const int N = 52;

int a[N][N];
int b[N][N];

void makeit (int x, int y) {
  b[x][y] = b[x + 1][y] = b[x][y + 1] = b[x + 1][y + 1] = 1;
}

bool check (int x, int y) {
  return a[x][y] && a[x + 1][y] && a[x][y + 1] && a[x + 1][y + 1];
}

void test_case() {
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  vector < pii > ans;
  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j + 1 < m; ++j) {
      if (check(i, j)) {
        makeit(i, j);
        ans.emplace_back(i, j);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != b[i][j]) {
        cout << "-1\n";
        return;
      }
    }
  }
  cout << sz(ans) << '\n';
  for (auto &[x, y] : ans) {
    cout << x + 1 << " " << y + 1 << '\n';
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
