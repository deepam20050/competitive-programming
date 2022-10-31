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

int cnt[31][2];

void test_case() {
  int l, r; cin >> l >> r;
  int n = r - l + 1;
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    for (int i = 0; i < 30; ++i) {
      ++cnt[i][x >> i & 1];
    }
  }
  int ans = 0;
  for (int i = 0; i < 30; ++i) {
    ans += (cnt[i][0] < cnt[i][1]) * (1 << i);
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