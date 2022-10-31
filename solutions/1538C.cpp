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
  int n, l, r; cin >> n >> l >> r;
  vector < int > a(n);
  for (auto &e : a) {
    cin >> e;
  }
  sort(all(a));
  auto f = [&] (int x) {
    return upper_bound(all(a), (int)2e9) - lower_bound(all(a), x);
  };
  lli ans = 0;
  vector < pii > tmp = {{l, 1}, {r + 1, - 1}};
  for (auto [base, mul] : tmp) {
    for (auto &e : a) {
      ans += mul * 1ll * f(base - e);
      ans += (e + e >= base ? -mul : 0);
    }
  }
  cout << ans / 2 << '\n';
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