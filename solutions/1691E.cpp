#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

const int N = 1e5 + 5;

int c[N], l[N], r[N];

struct DSU {
  vector < int > par, siz;
  DSU (int n) {
    par.clear(); siz.clear();
    par.resize(n); siz.resize(n);
    FOR(i, 0, n) {
      par[i] = i;
      siz[i] = 1;
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
    FOR(i, 0, sz(par)) {
      ans += find(i) == i;
    }
    return ans;
  }
};

void solveTestCase () {
  int n; scanf("%d", &n);
  vector < tuple < int, int, int > > points;
  points.reserve(2 * n);
  FOR(i, 0, n) {
    scanf("%d %d %d", c + i, l + i, r + i);
    points.eb(l[i], 0, i);
    points.eb(r[i], 1, i);
  }
  sort(all(points));
  vector < set < pii > > sets(2);
  DSU dsu(n);
  for (auto [ignore, close, i] : points) {
    int color = c[i];
    if (close) {
      sets[color].erase({r[i], i});
      continue;
    }
    sets[color].em(r[i], i);
    while (sz(sets[color ^ 1]) > 1) {
      auto [r_pos, idx_pos] = *sets[color ^ 1].begin();
      dsu.join(idx_pos, i);
      sets[color ^ 1].erase({r_pos, idx_pos});
    }
    if (sz(sets[color ^ 1]) == 1) {
      dsu.join(sets[color ^ 1].begin()->S, i);
    }
  }
  printf("%d\n", dsu.cnt_comps());
}

int main () {
  int _tc; scanf("%d", &_tc);
  while (_tc--) {
    solveTestCase();
  }
  return 0;
}