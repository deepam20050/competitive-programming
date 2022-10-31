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

int a[N];
int t[N << 2];

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
  t[x] = min(t[2 * x], t[2 * x + 1]);
}

int query (int lx, int rx, int x, int ql, int qr, int p) {
  if (t[x] > p) return 0;
  if (ql > rx || lx > qr || lx > rx) {
    return 0;
  }
  if (lx == rx) {
    t[x] = inf;
    return 1;
  }
  int midx = lx + rx >> 1;
  int f = query(lx, midx, 2 * x, ql, qr, p) + query(midx + 1, rx, 2 * x + 1, ql, qr, p);
  t[x] = min(t[2 * x], t[2 * x + 1]);
  return f;
}

void test_case() {
  int n, m; cin >> n >> m;  
  fill(t, t + (N << 2), inf);
  while (m--) {
    int op; cin >> op;
    if (op == 1) {
      int i, h; cin >> i >> h;
      update(0, n - 1, 1, i, h);
    } else {
      int l, r, p; cin >> l >> r >> p;
      cout << query(0, n - 1, 1, l, r - 1, p) << '\n';
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