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
  lli a, b, x, y, n; cin >> a >> b >> x >> y >> n;
  lli ans = 4e18;
  for (int i = 0; i < 2; ++i) {
    lli da = min(a - x, n);
    lli db = min(n - da, b - y);
    ans = min(ans, (a - da) * (b - db));
    swap(a, b);
    swap(x, y);
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