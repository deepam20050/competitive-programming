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
  vector < int > a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(1 + all(a));
  lli ans = 0;
  lli sum = 0;
  for (int i = 1; i <= n; ++i) {
    ans += -(a[i] * 1ll * (i - 1) - sum);
    sum += a[i];
  }
  ans += a.back();
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