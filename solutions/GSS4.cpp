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
lli maxi[N << 2];
lli a[N];
int n;

void build (int lx, int rx, int x) {
  if (lx == rx) {
    t[x] = a[lx];
    maxi[x] = a[lx];
    return;
  }
  int midx = lx + rx >> 1;
  build(lx, midx, 2 * x);
  build(midx + 1, rx, 2 * x + 1);
  t[x] = t[2 * x] + t[2 * x + 1];
  maxi[x] = max(maxi[2 * x], maxi[2 * x+ 1]);
}

void update (int lx, int rx, int x, int ql, int qr) {
  if (maxi[x] == 1) return;
  if (lx > qr || ql > rx) return;
  if (lx == rx) {
    maxi[x] = (lli)sqrt(maxi[x]);
    t[x] = maxi[x];
    return;
  }
  int midx = lx + rx >> 1;
  update(lx, midx, 2 * x, ql, qr);
  update(midx + 1, rx, 2 * x + 1, ql, qr);
  t[x] = t[2 * x] + t[2 * x + 1];
  maxi[x] = max(maxi[2 * x], maxi[2 * x + 1]);
}

lli query (int lx, int rx, int x, int ql, int qr) {
  if (lx > qr || ql > rx) return 0;
  if (ql <= lx && rx <= qr) {
    return t[x];
  }
  int midx = lx + rx >> 1;
  return query(lx, midx, 2 * x, ql, qr) + query(midx + 1, rx, 2 * x + 1, ql, qr);
}

void test_case() {
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  build(1, n, 1);
  int nq; cin >> nq;
  while (nq--) {
    int op, l, r; cin >> op >> l >> r;
    if (l > r) swap(l, r);
    if (!op) {
      update(1, n, 1, l, r);
    } else {
      cout << query(1, n, 1, l, r) << '\n';
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  while (cin >> n) {
    cout << "Case #" << nt++ << ":\n";
    test_case();
    cout << "\n";
  }
  return 0;
}