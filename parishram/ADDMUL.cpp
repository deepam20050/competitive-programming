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

lli t[N << 2];
lli lazy[2][N << 2];

void push (int lx, int rx, int x) {
  if (lazy[1][x]) {
    t[x] += (rx - lx + 1) * lazy[1][x];
    if (lx != rx) {
      lazy[1][2 * x] += lazy[1][x];
      lazy[1][2 * x + 1] += lazy[1][x];
      if (lazy[0][2 * x] != -1) {
        lazy[0][2 * x] += lazy[1][x];
      }
      if (lazy[0][2 * x + 1] != -1) {
        lazy[0][2 * x + 1] += lazy[1][x];
      }
    }
    lazy[1][x] = 0;
  }
  if (lazy[0][x] != -1) {
    t[x] = (rx - lx + 1) * lazy[0][x];
    if (lx != rx) {
      lazy[0][2 * x] = lazy[0][x];
      lazy[0][2 * x + 1] = lazy[0][x];
    }
    lazy[0][x] = -1;
  }
}

void build (int lx, int rx, int x) {
  lazy[0][x] = 
}

void update (int lx, int rx, int x, int ql, int qr, int i, int v) {
  push(lx, rx, x);
  if (lx > qr || ql > rx) return;
  if (ql <= lx && rx <= qr) {
    lazy[i][x] = v;
    push(lx, rx, x);
    return;
  }
  int midx = lx + rx >> 1;
  update(lx, midx, 2 * x, ql, qr, i, v);
  update(midx + 1, rx, 2 * x + 1, ql, qr, i, v);
  t[x] = t[2 * x] + t[2 * x + 1];
}

lli query (int lx, int rx, int x, int ql, int qr) {
  push(lx, rx, x);
  if (lx > qr || ql > rx) return 0;
  if (ql <= lx && rx <= qr) {
    return t[x];
  }
  int midx = lx + rx >> 1;
  return query(lx, midx, 2 * x, ql, qr) + query(midx + 1, rx, 2 * x + 1, ql, qr);
}

void test_case() {
  fill(lazy[0], lazy[0] + (N << 2), -1);
  int n, nq; cin >> n >> nq;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= nq; ++i) {
    int op; cin >> op;
    if (op == 4) {
      int l, r; cin >> l >> r;
      cout << query(0, n - 1, 1, l - 1, r - 1) << '\n';
    } else {
      int l, r, v; cin >> l >> r >> v;
      update(0, n - 1, 1, l - 1, r - 1, op - 1, v);
    }
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