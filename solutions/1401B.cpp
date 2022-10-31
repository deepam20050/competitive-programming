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
  int x1, y1, z1; cin >> x1 >> y1 >> z1;
  int x2, y2, z2; cin >> x2 >> y2 >> z2;
  int ans = 0;
  ans += 2 * min(z1, y2);
  int t = min(z1, y2);
  z1 -= t;
  y2 -= t;
  t = min(z1, z2);
  z1 -= t;
  z2 -= t;
  t = min(x1, z2);
  x1 -= t;
  z2 -= t;
  t = min(y1, x2);
  y1 -= t;
  x2 -= t;
  t = min(y1, y2);
  y1 -= t;
  y2 -= t;
  ans -= 2 * min(y1, z2);
  cout << ans << '\n';
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