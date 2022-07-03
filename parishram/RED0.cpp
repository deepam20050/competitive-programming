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
  lli x, y; cin >> x >> y;
  if (x > y) swap(x, y);
  if (x == y) {
    cout << x << '\n';
  } else if (x == 0) {
    cout << -1 << '\n';
  } else {
    lli ans = 0;
    while (x < y) {
      x <<= 1ll;
      ++ans;
    }
    ans += y;
    cout << ans << '\n';
  }
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