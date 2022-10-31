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
  int n, a; cin >> n >> a;
  vector < int > thief(n);
  for (auto &e : thief) {
    cin >> e;
  }
  --a;
  int ans = thief[a];
  for (int i = 1; i < n; ++i) {
    int c = 0;
    c += (a - i < 0) || (a - i >= 0 && thief[a - i]);
    c += (a + i >= n) || (a + i < n && thief[a + i]);
    if (c == 2) {
      ans += a - i >= 0 && thief[a - i];
      ans += a + i < n && thief[a + i];
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