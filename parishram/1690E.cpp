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
  lli ans = 0;
  multiset < int > s;
  for (int i = 0; i < n; ++i) {
    int e; cin >> e;
    ans += e / k;
    e %= k;
    s.emplace(e);
  }
  while (!s.empty()) {
    auto it = --s.end();
    int x = *it;
    s.erase(it);
    auto it2 = s.lower_bound(k - x);
    if (it2 == s.end()) {
      s.erase(s.begin());
    } else {
      ++ans;
      s.erase(it2);
    }
  }
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