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

void test_case() {
  int n, k; cin >> n >> k;
  vector < int > a(n);
  for (auto &e : a) {
    cin >> e;
  }
  sort(all(a), greater < int > ());
  lli ans = 0;
  for (int i = 0; i < k; ++i) {
    ans += a[i + k] / a[i];
  }
  ans += accumulate(2 * k + all(a), 0ll);
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