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
using t4 = tuple < int, int, int, int >;

void test_case() {
  int n, m; cin >> n >> m;
  vector < string > a(n, "");
  for (auto &e : a) {
    cin >> e;
  }
  function < bool (int, int) > check = [&] (int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
  };
  vector < t4 > ans;
  vector < string > b(n, string(m, '0'));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      if (a[i][j] == '1') {
        if (check(i - 1, j)) {
          ans.emplace_back(i - 1, j, i, j);
          b[i][j] = '1';
        } else if (check(i, j - 1)) {
          ans.emplace_back(i, j - 1, i, j);
          b[i][j] = '1';
        }
      }
    }
  }
  debug(a, b);
  if (a != b || sz(ans) > n * m) {
    cout << "-1\n";
  } else {
    cout << sz(ans) << '\n';
    for (auto &[x, y, w, z] : ans) {
      cout << x + 1 << " " << y + 1 << " " << w + 1 << " " << z + 1 << '\n';
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
