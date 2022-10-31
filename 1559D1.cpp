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

struct DSU {
  vector < int > par, siz;
  DSU (int n) {
    par.assign(n, 0);
    siz.assign(n, 1);
    iota(all(par), 0);
  }
  int find (int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
  }
  bool join (int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    if (siz[x] < siz[y]) {
      swap(x, y);
    }
    par[y] = x;
    siz[x] += siz[y];
    return 1;
  }
  bool is_same (int x, int y) {
    x = find(x);
    y = find(y);
    return x == y;
  }
  int cnt_comps () {
    int ans = 0;
    for (int i = 0; i < sz(par); ++i) {
      ans += find(i) == i;
    }
    return ans;
  }
};

void test_case() {
  int n, m1, m2; cin >> n >> m1 >> m2;
  DSU t1(n + 5), t2(n + 5);
  for (int i = 0; i < m1; ++i) {
    int x, y; cin >> x >> y;
    t1.join(x, y);
  }
  for (int i = 0; i < m2; ++i) {
    int x, y; cin >> x >> y;
    t2.join(x, y);
  }
  vector < pii > ans;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (!t1.is_same(i, j) && !t2.is_same(i, j)) {
        t1.join(i, j);
        t2.join(i, j);
        ans.emplace_back(i, j);
      }
    }
  }
  cout << sz(ans) << '\n';
  for (auto &[x, y] : ans) {
    cout << x << " " << y << '\n';
  }
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
