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

const int N = 1e5 + 5;
const int inf = 2e9;

struct node {
  lli pref, suff, best, total;
} t[N << 2];

const node none = {0, 0, 0, 0};

int lazy[N << 2];

void push (int lx, int rx, int x) {
  if (lazy[x] == inf) return;
  lli c = rx - lx + 1;
  t[x] = {c * lazy[x], c * lazy[x], c * lazy[x], c * lazy[x]};
  if (lx != rx) {
    lazy[2 * x] = lazy[x];
    lazy[2 * x + 1] = lazy[x];
  }
  lazy[x] = inf;
}

node join (const node &l, const node &r) {
  node ret = {max(l.pref, l.total + r.pref), max(r.suff, r.total + l.suff), 0, l.total + r.total};
  ret.best = max({l.suff + r.pref, l.total + r.total, l.best, r.best});
  return ret;
}

void update (int lx, int rx, int x, int ql, int qr, int v) {
  push(lx, rx, x);
  if (lx > qr || ql > rx) return;
  if (ql <= lx && rx <= qr) {
    lazy[x] = v;
    push(lx, rx, x);
    return;
  }
  int midx = lx + rx >> 1;
  update(lx, midx, 2 * x, ql, qr, v);
  update(midx + 1, rx, 2 * x + 1, ql, qr, v);
  t[x] = join(t[2 * x], t[2 * x + 1]);
}

node query (int lx, int rx, int x, int ql, int qr) {
  push(lx, rx, x);
  if (lx > qr || ql > rx) return none;
  if (ql <= lx && rx <= qr) {
    return t[x];
  }
  int midx = lx + rx >> 1;
  return join(query(lx, midx, 2 * x, ql, qr), query(midx + 1, rx, 2 * x + 1, ql, qr));
}

void test_case() {
  int n, nq; cin >> n >> nq;
  fill(lazy, lazy + (N << 2), inf);
  while (nq--) {
    int l, r, v; cin >> l >> r >> v;
    update(0, n - 1, 1, l, r - 1, v);
    cout << max(0ll, query(0, n - 1, 1, 0, n - 1).best) << '\n';
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