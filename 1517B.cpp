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
  int n, m; cin >> n >> m;
  vector < vector < int > > a(n, vector < int > (m, 0));
  vector < array < int, 3 > > v;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      v.push_back({a[i][j], i, j});
    }
  }
  sort(all(v));
  vector < vector < int > > ans(n, vector < int > (m, -1));
  for (int i = 0; i < m; ++i) {
    auto [val, r, c] = v[i];
    ans[r][i] = val;
    a[r][c] = -val;
  }
  for (int i = 0; i < n; ++i) {
    sort(all(a[i]));
    for (int j = 0; j < m; ++j) {
      if (ans[i][j] == -1) {
        ans[i][j] = a[i].back();
        a[i].pop_back();
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << ans[i][j] << " \n"[j == m - 1];
    }
  }
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
