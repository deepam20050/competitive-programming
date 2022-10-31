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

const int N = 2002;

int d[N][N];
vector < pii > g[N];
bool used[N];

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
  int cnt_comps () {
    int ans = 0;
    for (int i = 0; i < sz(par); ++i) {
      ans += find(i) == i;
    }
    return ans;
  }
};

void test_case() {
  int n; cin >> n;
  DSU dsu(n);
  vector < array < int, 3 > > edges;
  edges.reserve(n * n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> d[i][j];
      if (i == j && d[i][j]) {
        cout << "NO\n";
        return;
      }
      if (i != j && !d[i][j]) {
        cout << "NO\n";
        return;
      }
      edges.push_back({d[i][j], i, j});
    }
  }
  sort(all(edges));
  for (auto &[w, x, y] : edges) {
    if (dsu.join(x, y)) {
      g[x].emplace_back(y, w);
      g[y].emplace_back(x, w);
    }
  }
  bool ok = 1;
  int start = 0;
  int cnt = 0;
  function <void (int, int, lli)> dfs = [&] (int u, int p, lli len) {
    used[u] = 1;
    ok &= d[start][u] == len;
    for (auto [to, w] : g[u]) {
      if (to != p) {
        ++cnt;
        dfs(to, u, len + w);
      }
    } 
  };
  for (int i = 0; i < n; ++i) {
    start = i;
    dfs(i, -1, 0);
    ok &= accumulate(used, used + n, 0) == n;
  }
  ok ? cout << "YES\n" : cout << "NO\n";
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