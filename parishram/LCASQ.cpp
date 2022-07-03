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

const int N = 4e4 + 2;

vector < int > g[N];
int first[N];
int t[N << 2];
int height[N];
vector < int > euler;
int m;

void dfs (int u, int p, int h) {
  height[u] = h;
  first[u] = sz(euler);
  euler.emplace_back(u);
  for (auto &to : g[u]) {
    if (to != p) {
      dfs(to, u, h + 1);
      euler.emplace_back(u);
    }
  }
}

void build (int lx, int rx, int x) {
  if (lx == rx) {
    t[x] = euler[lx];
    return;
  }
  int midx = lx + rx >> 1;
  build(lx, midx, 2 * x);
  build(midx + 1, rx, 2 * x + 1);
  if (height[t[2 * x]] <= height[t[2 * x + 1]]) {
    t[x] = t[2 * x];
  } else {
    t[x] = t[2 * x + 1];
  }
}

int query (int lx, int rx, int x, int ql, int qr) {
  if (lx > qr || ql > rx) {
    return -1;
  }
  if (ql <= lx && rx <= qr) {
    return t[x];
  }
  int midx = lx + rx >> 1;
  int ansl = query(lx, midx, 2 * x, ql, qr);
  int ansr = query(midx + 1, rx, 2 * x + 1, ql, qr);
  if (ansl == -1) return ansr;
  if (ansr == -1) return ansl;
  return height[ansl] < height[ansr] ? ansl : ansr;
}

int lca (int u, int v) {
  int l = first[u], r = first[v];
  if (l > r) {
    swap(l, r);
  }
  return query(0, m - 1, 1, l, r);
}

void test_case() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    int d; cin >> d;
    g[i].resize(d);
    for (auto &e : g[i]) {
      cin >> e;
    }
  }
  euler.reserve(2 * n);
  dfs(0, 0, 0);
  m = sz(euler);
  build(0, m - 1, 1);
  int nq; cin >> nq;
  while (nq--) {
    int u, v; cin >> u >> v;
    cout << lca(u, v) << '\n';
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