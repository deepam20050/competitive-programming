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

void change (int &a, int b) {
  a += b;
}

void push (int lx, int rx, int x) {
  if (!lazy[x]) return;
  t[x] = (lazy[x] & 1) ? (rx - lx + 1 - t[x]) : t[x];
  if (lx != rx) {
    change(lazy[2 * x], lazy[x]);
    change(lazy[2 * x + 1], lazy[x]);
  }
  lazy[x] = 0;
}

void update (int lx, int rx, int x, int ql, int qr) {
  push(lx, rx, x);
  if (lx > qr || ql > rx) return;
  if (ql <= lx && rx <= qr) {
    change(lazy[x], 1);
    push(lx, rx, x);
    return;
  }
  int midx = lx + rx >> 1;
  update(lx, midx, 2 * x, ql, qr);
  update(midx + 1, rx, 2 * x + 1, ql, qr);
  t[x] = t[2 * x] + t[2 * x + 1];
}

int find_kth_one (int lx, int rx, int x, int k) { 
  push(lx, rx, x);
  if (t[x] < k) return -1;
  if (lx == rx) {
    return lx;
  }
  int midx = lx + rx >> 1;
  int ansl = find_kth_one(lx, midx, 2 * x, k);
  return ansl != -1 ? ansl : find_kth_one(midx + 1, rx, 2 * x + 1, k - t[2 * x]);
}

void test_case() {
  int n, nq; cin >> n >> nq;
  while (nq--) {
    int op; cin >> op;
    if (op == 1) {
      int l, r; cin >> l >> r;
      update(0, n - 1, 1, l, r - 1);
    } else {
      int k; cin >> k;
      cout << find_kth_one(0, n - 1, 1, k + 1) << '\n';
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