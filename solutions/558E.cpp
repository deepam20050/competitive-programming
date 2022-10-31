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

string s;

struct SegTree {
  int lazy[N << 2];
  int t[N << 2];
  void build (int lx, int rx, int x, int i) {
    lazy[x] = -1;
    if (lx == rx) {
      t[x] = s[lx - 1] - 'a' == i;
      return;
    }
    int midx = lx + rx >> 1;
    build(lx, midx, 2 * x, i);
    build(midx + 1, rx, 2 * x + 1, i);
    t[x] = t[2 * x] + t[2 * x + 1];
  }
  void push (int lx, int rx, int x) {
    if (lazy[x] == -1) return;
    t[x] = (rx - lx + 1) * lazy[x];
    if (lx != rx) {
      lazy[2 * x] = lazy[x];
      lazy[2 * x + 1] = lazy[x];
    }
    lazy[x] = -1;
  }
  void update (int lx, int rx, int x, int ql, int qr, int val) {
    push(lx, rx, x);
    if (lx > qr || ql > rx) return;
    if (ql <= lx && rx <= qr) {
      lazy[x] = val;
      push(lx, rx, x);
      return;
    }
    int midx = lx + rx >> 1;
    update(lx, midx, 2 * x, ql, qr, val);
    update(midx + 1, rx, 2 * x + 1, ql, qr, val);
    t[x] = t[2 * x] + t[2 * x + 1];
  }
  int query (int lx, int rx, int x, int ql, int qr) {
    push(lx, rx, x);
    if (lx > qr || ql > rx) return 0;
    if (ql <= lx && rx <= qr) {
      return t[x];
    }
    int midx = lx + rx >> 1;
    return query(lx, midx, 2 * x, ql, qr) + query(midx + 1, rx, 2 * x + 1, ql, qr);
  }
} tree[26];

void test_case() {
  int n, nq; cin >> n >> nq;
  cin >> s;
  for (int i = 0; i < 26; ++i) {
    tree[i].build(1, n, 1, i);
  }
  while (nq--) {
    int op, l, r; cin >> l >> r >> op;
    int curr = l;
    if (op) {
      for (int i = 0; i < 26; ++i) {
        int cnt = tree[i].query(1, n, 1, l, r);
        tree[i].update(1, n, 1, l, r, 0);
        if (cnt) {
          tree[i].update(1, n, 1, curr, curr + cnt - 1, 1);
        }
        curr += cnt;
      }
    } else {
      for (int i = 25; i >= 0; --i) {
        int cnt = tree[i].query(1, n, 1, l, r);
        tree[i].update(1, n, 1, l, r, 0);
        if (cnt) {
          tree[i].update(1, n, 1, curr, curr + cnt - 1, 1);
        }
        curr += cnt;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (tree[j].query(1, n, 1, i, i)) {
        cout << char(j + 'a');
        break;
      }
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