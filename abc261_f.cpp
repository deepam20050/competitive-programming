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

const int N = 3e5 + 5;

int c[N], x[N];
vector < pii > color[N];
pii p[N];

template < class T > struct FenwickTree {
  vector < T > t;
  int n;
  FenwickTree (int m) : n(m) {
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
  T rangeQuery (int l, int r) {
    return query(r) - query(l - 1);
  }
};
FenwickTree < int > bit1(N);

void test_case() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    p[i - 1] = {x[i], i};
    color[c[i]].emplace_back(x[i], i);
  }
  sort(p, p + n);
  lli ans = 0;
  for (int i = 0; i < n; ++i) {
    auto [val, pos] = p[i];
    ans += bit1.query(n) - bit1.query(pos);
    bit1.update(pos, 1);
  }
  bit1.t.assign(N, 0);
  for (int i = 1; i <= n; ++i) {
    sort(all(color[i]));
    int m = sz(color[i]);
    for (auto [val, pos] : color[i]) {
      ans -= bit1.query(n) - bit1.query(pos);
      bit1.update(pos, 1);
    }
    for (auto [val, pos] : color[i]) {
      bit1.update(pos, -1);
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
