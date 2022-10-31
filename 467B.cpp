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
  int n, m, k; cin >> n >> m >> k;
  vector < int > a(m + 1);
  for (int i = 0; i < m + 1; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    ans += __builtin_popcount(a[i] ^ a[m]) <= k;
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