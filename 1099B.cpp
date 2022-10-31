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
  int x = sqrt(n);
  int ans = 2e9;
  for (int i = x - 5; i <= x + 5; ++i) {
    for (int j = x - 5; j <= x + 5; ++j) {
      if (i > 0 && j > 0 && i * j >= n) {
        ans = min(ans, i + j);
      }
    }
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
