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

int a[N];
lli t[N << 2];

void build (int lx, int rx, int x) {
  if (lx == rx) {
    t[x] = a[lx];
    return;
  }
  int midx = lx + rx >> 1;
  build(lx, midx, 2 * x);
  build(midx + 1, rx, 2 * x + 1);
  t[x] = t[2 * x] + t[2 * x + 1];
}

void update (int lx, int rx, int x, int pos, int val) {
  if (lx == rx) {
    t[x] = val;
    return;
  }
  int midx = lx + rx >> 1;
  if (pos <= midx) {
    update(lx, midx, 2 * x, pos, val);
  } else {
    update(midx + 1, rx, 2 * x + 1, pos, val);
  }
  t[x] = t[2 * x] + t[2 * x + 1];
}

lli query (int lx, int rx, int x, int ql, int qr) {
  if (lx > qr || ql > rx) {
    return 0;
  }
  if (ql <= lx && rx <= qr) {
    return t[x];
  }
  int midx = lx + rx >> 1;
  return query(lx, midx, 2 * x, ql, qr) + query(midx + 1, rx, 2 * x + 1, ql, qr);
}

void test_case() {
  int n, nq; cin >> n >> nq;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  build(0, n - 1, 1);
  while (nq--) {
    int op; cin >> op;
    if (op == 1) {
      int i, v; cin >> i >> v;
      update(0, n - 1, 1, i, v);
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