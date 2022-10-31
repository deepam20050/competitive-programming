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
  int n, m; cin >> n >> m;
  vector < int > a(m);
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    ++a[x % m];
  }
  debug(a);
  int ans = a[0] > 0;
  for (int i = 1, j = m - 1; i < j; ++i, --j) {
    int x = min(a[i], a[j]);
    if (x == 0) {
      ans += a[i];
      ans += a[j];
      continue;
    } else if (a[i] == a[j]) {
      ++ans;
    } else {
      ans += 1;
      ++x;
      a[i] -= min(a[i], x);
      a[j] -= min(a[j], x);
      ans += a[i];
      ans += a[j];
    }
  }
  if (m % 2 == 0) {
    ans += a[m / 2] > 0;
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