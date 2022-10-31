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
  vector < int > a(n);
  for (auto &e : a) {
    cin >> e;
  }
  if (n == 1) {
    cout << 0 << '\n';
    return;
  }
  int ans = n;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int curr = 0;
      for (int k = 0; k < n; ++k) {
        curr += a[k] * (j - i) != a[i] * (j - i) + (a[j] - a[i]) * (k - i);
      }
      ans = min(ans, curr);
    }
  }
  debug(ans);
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