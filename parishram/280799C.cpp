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

lli sum[N << 2];
lli t[N << 2];

void push (int lx, int rx, int x) {
  if (!sum[x]) return;
  t[x] += sum[x];
  if (lx != rx) {
    sum[2 * x] += sum[x];
    sum[2 * x + 1] += sum[x];
  }
  sum[x] = 0;
}

void update (int lx, int rx, int x, int ql, int qr, int v) {
  push(lx, rx, x);
  if (lx > qr || ql > rx) return;
  if (ql <= lx && rx <= qr) {
    sum[x] += v;
    push(lx, rx, x);
    return;
  }
  int midx = lx + rx >> 1;
  update(lx, midx, 2 * x, ql, qr, v);
  update(midx + 1, rx, 2 * x + 1, ql, qr, v);
  t[x] = max(t[2 * x], t[2 * x + 1]);
}

int find_kth_one (int lx, int rx, int x, int ql, int v) {
  push(lx, rx, x);
  if (t[x] < v) return -1;
  if (ql > rx) return -1;
  if (lx == rx) {
    return lx;
  }
  int midx = lx + rx >> 1;
  int ansl = find_kth_one(lx, midx, 2 * x, ql, v);
  return ansl != -1 ? ansl : find_kth_one(midx + 1, rx, 2 * x + 1, ql, v);
}

void test_case() {
  int n, nq; cin >> n >> nq;
  while (nq--) {
    int op; cin >> op;
    if (op == 1) {
      int l, r, v; cin >> l >> r >> v;
      update(0, n - 1, 1, l, r - 1, v);
    } else {
      int v, l; cin >> v >> l;
      cout << find_kth_one(0, n - 1, 1, l, v) << '\n';
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