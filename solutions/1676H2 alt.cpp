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

template < class T >
struct FenwickTree {
  vector < T > t;
  int n;
  FenwickTree (int m) : n(m) {
    t.clear();
    t.resize(n + 1);
  }
  void update (int idx, T add) {
    while (idx <= n) {
      t[idx] += add;
      idx += idx & -idx;
    }
  }
  T query (int idx) {
    T ret = 0;
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
  FenwickTree < int > t(n + 1);
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