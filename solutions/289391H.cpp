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

const int N = 1e5 + 5;

array < int, 4 > edges[N];
bool used[N];

void test_case() {
  int n, m; lli s; cin >> n >> m >> s;
  for (int i = 0; i < m; ++i) {
    auto &[c, a, b, idx] = edges[i];
    cin >> a >> b >> c;
    c = -c;
    idx = i;
  }
  sort(edges, edges + m);
  DSU dsu(n + 1);
  for (int i = 0; i < m; ++i) {
    auto &[c, a, b, idx] = edges[i];
    if (!dsu.join(a, b)) {
      used[i] = 1;
    }
  }
  vector < int > ans;
  for (int i = m - 1; i >= 0; --i) {
    auto &[c, a, b, idx] = edges[i];
    c = -c;
    if (used[i] && s >= c) {
      ans.emplace_back(idx);
      s -= c;
    }
  }
  cout << sz(ans) << '\n';
  for (auto &e : ans) {
    cout << e + 1 << " ";
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