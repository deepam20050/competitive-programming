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
  int n; cin >> n;
  vector < lli > a(n);
  lli odd = 0, even = -1;
  int ans = 0;
  for (auto &x : a) {
    cin >> x;
    if (x % 2 == 0) {
      int add = __builtin_ctzll(x);
      x >>= add;
      ans += add;
      even = max(even, x);
    } else {
      odd = max(odd, x);
    }
  }
  lli what = max(odd, even);
  cout << accumulate(all(a), 0ll) - what + what * (1ll << ans) << '\n';
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