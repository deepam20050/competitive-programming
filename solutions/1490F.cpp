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
  map < int, int > cnt;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    ++cnt[x];
  }
  map < int, int > freq;
  for (auto [ignore, c] : cnt) {
    ++freq[c];
  }
  int pref = 0;
  int ans = n;
  int l = 0, r = n, rcnt = sz(cnt);
  for (auto[x, y] : freq) {
    ans = min(ans, l + r - rcnt * x);
    l += x * y;
    r -= x * y;
    rcnt -= y;
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