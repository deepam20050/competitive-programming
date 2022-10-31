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
const int MOD = 1e9 + 7;

int mul (int a, int b) {
  return a * 1ll * b % MOD;
}

int add (int a, int b) {
  a += b;
  return a >= MOD ? a -= MOD : a;
}

int lazy[N << 2];
int t[N << 2];

void push (int lx, int rx, int x) {
  if (lazy[x] == 1) return;
  t[x] = mul(t[x], lazy[x]);
  if (lx != rx) {
    lazy[2 * x] = mul(lazy[2 * x], lazy[x]);
    lazy[2 * x + 1] = mul(lazy[2 * x + 1], lazy[x]);
  }
  lazy[x] = 1;
}

void build (int lx, int rx, int x) {
  lazy[x] = 1;
  if (lx == rx) {
    t[x] = 1;
    return;
  }
  int midx = lx + rx >> 1;
  build(lx, midx, 2 * x);
  build(midx + 1, rx, 2 * x + 1);
  t[x] = t[2 * x] + t[2 * x + 1];
}

void update (int lx, int rx, int x, int ql, int qr, int v) {
  push(lx, rx, x);
  if (lx > qr || ql > rx) return;
  if (ql <= lx && rx <= qr) {
    lazy[x] = mul(lazy[x], v);
    push(lx, rx, x);
    return;
  }
  int midx = lx + rx >> 1;
  update(lx, midx, 2 * x, ql, qr, v);
  update(midx + 1, rx, 2 * x + 1, ql, qr, v);
  t[x] = add(t[2 * x], t[2 * x + 1]);
}

int query (int lx, int rx, int x, int ql, int qr) {
  push(lx, rx, x);
  if (lx > qr || ql > rx) return 0;
  if (ql <= lx && rx <= qr) {
    return t[x];
  }
  int midx = lx + rx >> 1;
  return add(query(lx, midx, 2 * x, ql, qr), query(midx + 1, rx, 2 * x + 1, ql, qr));
}

void test_case() {
  int n, nq; cin >> n >> nq;
  build(0, n - 1, 1);
  while (nq--) {
    int op; cin >> op;
    if (op == 1) {
      int l, r, v; cin >> l >> r >> v;
      update(0, n - 1, 1, l, r - 1, v);
    } else {
      int l, r; cin >> l >> r;
      cout << query(0, n - 1, 1, l, r - 1) << '\n';
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