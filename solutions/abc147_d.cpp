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

const lli MOD = 1e9 + 7;

void test_case() {
  int n; cin >> n;
  vector < int > freq(60);
  for (int i = 0; i < n; ++i) {
    lli x; cin >> x;
    for (int j = 0; j < 60; ++j) {
      freq[j] += x >> j & 1;
    }
  }
  lli ans = 0;
  for (int i = 0; i < 60; ++i) {
    lli mul1 = (1ll << i) % MOD;
    lli mul2 = freq[i] * 1ll * (n - freq[i]) % MOD;
    ans += mul1 * mul2 % MOD;
    ans %= MOD;
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
