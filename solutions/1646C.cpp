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

const int LN = 16;

lli f[LN];

void init () {
  f[0] = 1;
  for (int i = 1; i < LN; ++i) {
    f[i] = f[i - 1] * i;
  }
}

void test_case() {
  lli n; cin >> n;
  int ans = __builtin_popcountll(n);
  debug(ans);
  for (int i = 0; i < (1 << LN); ++i) {
    lli x = 0;
    int c = 0;
    for (int j = 0; j < LN; ++j) {
      if (i >> j & 1) {
        x += f[j];
        ++c;
      }
    }
    if (x == n) {
      ans = min(ans, c);
    } 
    if (x < n) {
      ans = min(ans, c + __builtin_popcountll(n - x));
    }
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  init();
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}