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
  int n; cin >> n;
  vector < int > v(n);
  for (auto &e : v) {
    cin >> e;
  }
  if ((n == 3 && v[1] % 2 ==  1) || (*max_element(v.begin() + 1, v.end() - 1) == 1)) {
    cout << -1 << '\n';
    return;
  } else {
    lli ans = 0;
    for (int i = 1; i < n - 1; ++i) {
      ans += v[i] + 1 >> 1;
    }
    cout << ans << '\n';
  }
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