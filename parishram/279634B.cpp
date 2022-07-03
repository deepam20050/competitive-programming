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

int t[N << 2];
int lazy[N << 2];

void push (int lx, int rx, int x) {
  t[x] = max(t[x], lazy[x]);
  if (lx != rx) {
    lazy[2 * x] = max(lazy[2 * x], lazy[x]);
    lazy[2 * x + 1] = max(lazy[2 * x + 1], lazy[x]);
  }
  lazy[x] = 0;
}

void update (int lx, int rx, int x, int ql, int qr, int v) {
  push(lx, rx, v);
  if (lx > qr || ql > rx) return;
  if (ql <= lx && rx <= qr) {
    lazy[x] = max(lazy[x], v);
    return;
  }
  int midx = lx + rx >> 1;
  update(lx, midx, 2 * x, ql, qr, v);
  update(midx + 1, rx, 2 * x + 1, ql, qr, v);
}

int query (int lx, int rx, int x, int pos) {
  push(lx, rx, x);
  if (lx == rx) {
    return t[x];
  }
  int midx = lx + rx >> 1;
  return pos <= midx ? query(lx, midx, 2 * x, pos) : query(midx + 1, rx, 2 * x + 1, pos);
}

void test_case() {
  int n, nq; cin >> n >> nq;
  while (nq--) {
    int op; cin >> op;
    if (op == 1) {
      int l, r, v; cin >> l >> r >> v;
      update(0, n - 1, 1, l, r - 1, v);
    } else {
      int i; cin >> i;
      cout << query(0, n - 1, 1, i) << '\n';
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