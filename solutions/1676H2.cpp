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

int n;

struct FenwickTree {
  vector < int > t;
  int n;
  FenwickTree (int m) : n(m) {
    t.assign(n + 1, 0);
  }
  void update (int idx, int add) {
    while (idx <= n) {
      t[idx] += add;
      idx += idx & -idx;
    }
  }
  int query (int idx) {
    int ret = 0;
    while (idx > 0) {
      ret += t[idx];
      idx -= idx & -idx;
    }
    return ret;
  }
};

void test_case() {
  int n; cin >> n;
  vector < pii > v(n);
  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    v[i - 1] = {x, -i};
  }
  sort(all(v), greater < pii > ());
  lli ans = 0;
  FenwickTree t(n + 1);
  for (auto [ignore, idx] : v) {
    idx = -idx;
    ans += t.query(idx);
    t.update(idx, 1);
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