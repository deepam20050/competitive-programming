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

int get (int x, int y) {
  return (x + y - 1) / y;
}

void test_case() {
  int n; cin >> n;
  int ans = 1e9;
  for (int i = 1; i * i <= n; ++i) {
    ans = min(ans, i - 1 + get(n - i, i));
  }
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