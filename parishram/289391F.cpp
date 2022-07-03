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
    rep(i, 0, n) {
      par[i] = i;
    }
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
  int cnt_comps () {
    int ans = 0;
    for (int i = 0; i < sz(par); ++i) {
      ans += find(i) == i;
    }
    return ans;
  }
};

void test_case() {
  int n, m; cin >> n >> m;
  vector < array < int, 3 > > edges(m);
  for (auto &[c, a, b] : edges) {
    cin >> a >> b >> c;
  }
  sort(all(edges));
  int ans = 2e9 + 5;
  for (int i = 0; i < m; ++i) {
    DSU dsu(n + 1);
    int mx = -2e9;
    for (int j = i; j < m; ++j) {
      if (dsu.join(edges[j][1], edges[j][2])) {
        mx = edges[j][0];
      }
    }
    if (dsu.siz[dsu.find(edges[i][1])] == n) {
      ans = min(ans, mx - edges[i][0]);
    }
  }
  if (ans == (int)2e9 + 5) {
    cout << "NO\n";
  } else {
    cout << "YES\n" << ans << '\n';
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}