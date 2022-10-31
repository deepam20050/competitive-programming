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
  vector < lli > a(n);
  for (auto &e : a) {
    cin >> e;
  }
  lli ans = 0;
  lli pos = 0;
  for (auto &e : a) {
    if (e > 0) {
      pos += e;
    } else if (e < 0) {
      lli t = min(pos, -e);
      e += t;
      pos -= t;
      ans -= e;
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