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

const int N = 2e5 + 5;
const lli inf = 4e18;

lli t[N << 2];
lli a[N << 2];
lli d[N << 2];

void push (int lx, int rx, int x) {
  if (a[x] == inf || d[x] == inf) return;
  t[x] += a[x] + d[x];
  if (lx != rx) {
    int midx = lx + rx >> 1;
    if (a[2 * x] == inf) {
      a[2 * x] = a[x];
    } else {
      a[2 * x] += a[x];
    }
    if (d[2 * x] == inf) {
      d[2 * x] = d[x];
    } else {
      d[2 * x] += d[x];
    }
    if (a[2 * x + 1] == inf) {
      a[2 * x + 1] = a[x] + d[x] * (midx - lx + 1);
    } else {
      a[2 * x + 1] += a[x] + d[x] * (midx - lx + 1);
    }
    if (d[2 * x + 1] == inf) {
      d[2 * x + 1] = d[x];
    } else {
      d[2 * x + 1] +=  d[x];
    }
  }
  d[x] = inf;
  a[x] = inf;
}

int update (int lx, int rx, int x, int ql, int qr, int add, int diff, int prev) {
  push(lx, rx, x);
  if (lx > qr || ql > rx) return 0;
  if (ql <= lx && rx <= qr) {
    a[x] = 1ll * add + (prev - 1) * 1ll * diff;
    d[x] = diff;
    push(lx, rx, x);
    return rx - lx + 1;
  }
  int midx = lx + rx >> 1;
  int extra = update(lx, midx, 2 * x, ql, qr, add, diff, prev);
  return update(midx + 1, rx, 2 * x + 1, ql, qr, add, diff, prev + extra);
}

lli query (int lx, int rx, int x, int pos) {
  push(lx, rx, x);
  if (lx == rx) {
    return t[x];
  }
  int midx = lx + rx >> 1;
  return pos <= midx ? query(lx, midx, 2 * x, pos) : query(midx + 1, rx, 2 * x + 1, pos);
}

void test_case() {
  fill(a, a + (N << 2), inf);
  fill(d, d + (N << 2), inf);
  int n, nq; cin >> n >> nq;
  while (nq--) {
    int op; cin >> op;
    if (op == 1) {
      int l, r, a, d; cin >> l >> r >> a >> d;
      update(1, n, 1, l, r, a, d, 0);
    } else {
      int i; cin >> i;
      cout << query(1, n, 1, i) << '\n';
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