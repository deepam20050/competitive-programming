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

using arr = array < int, 5 >;

arr get (int x) {
  arr ret;
  ret[0] = x / 5;
  int r = x % 5;
  for (int i = 1; i < 5; ++i) {
    ret[i] = ret[0] + (i <= r);
  }
  return ret;
}

void test_case() {
  int n, m; cin >> n >> m;
  auto a = get(n), b = get(m);
  lli ans = a[0] * 1ll * b[0];
  for (int i = 1; i < 5; ++i) {
    ans += a[i] * 1ll * b[5 - i];
  }
  cout << ans << '\n';
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