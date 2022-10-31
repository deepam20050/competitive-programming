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

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

void test_case() {
  int n; cin >> n;
  vector < string > a(n, string(n, '0'));
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  function < int (int, int) > check = [&] (int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n ? a[x][y] - '0' : -1;
  };
  vector < pii > ans1, ans2;
  for (int i = 0; i < 4; ++i) {
    if (check(dx[i], dy[i]) == 1) {
      ans1.emplace_back(dx[i], dy[i]);
    }
    if (check(n - 1 + dx[i], n - 1 + dy[i]) == 0) {
      ans1.emplace_back(n - 1 + dx[i], n - 1 + dy[i]);
    }
  }
  for (int i = 0; i < 4; ++i) {
    if (check(dx[i], dy[i]) == 0) {
      ans2.emplace_back(dx[i], dy[i]);
    }
    if (check(n - 1 + dx[i], n - 1 + dy[i]) == 1) {
      ans2.emplace_back(n - 1 + dx[i], n - 1 + dy[i]);
    }
  }
  vector < pii > ans = sz(ans1) < sz(ans2) ? ans1 : ans2;
  cout << sz(ans) << '\n';
  for (auto [x, y] : ans) {
    cout << x + 1 << " " << y + 1 << '\n';
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
