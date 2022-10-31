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
  string s; cin >> s;
  int x; cin >> x;
  int n = sz(s);
  string ans(n, '1');
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      if (i - x >= 0) {
        ans[i - x] = '0';
      }
      if (i + x < n) {
        ans[i + x] = '0';
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      bool ok = 0;
      if (i - x >= 0) {
        ok |= ans[i - x] == '1';
      }
      if (i + x < n) {
        ok |= ans[i + x] == '1';
      }
      if (!ok) {
        cout << -1 << '\n';
        return;
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
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}