#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 5;
const int M = 42;

int a[N];

struct SegTree {
  long long t[N << 2];
  void build (int node, int l, int r) {
    if (l == r) {
      t[node] = 1ll << a[l];
      return;
    }
    int mid = l + r >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    t[node] = t[node << 1] | t[node << 1 | 1];
  }
  void update (int node, int l, int r, int x, int y) {
    if (l == r) {
      t[node] = 0;
      t[node] |= 1ll << y;
      return;
    }
    int mid = l + r >> 1;
    if (x <= mid) {
      update(node << 1, l, mid, x, y);
    } else {
      update(node << 1 | 1, mid + 1, r, x, y);
    }
    t[node] = t[node << 1] | t[node << 1 | 1];
  }
  long long query (int node, int lx, int rx, int ql, int qr) {
    if (lx > qr || ql > rx) {
      return 0;
    }
    if (ql <= lx && rx <= qr) {
      return t[node];
    }
    int midx = lx + rx >> 1;
    return query(2 * node, lx, midx, ql, qr) | query(2 * node + 1, midx + 1, rx, ql, qr);
  }
};

SegTree tree1;

int main () {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  tree1.build(1, 1, n);
  while (q--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == 1) {
      printf("%d\n", __builtin_popcountll(tree1.query(1, 1, n, b, c)));
    } else {
      tree1.update(1, 1, n, b, c);
    }
  }
  return 0;
}