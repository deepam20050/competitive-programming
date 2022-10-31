#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 5;
const int M = N << 2;

int a[N];
int b[N];
int a_pos[N];
int b_pos[N];
int len[N];

struct SegTree {
  int t[M];
  bitset < M > lzy;
  void propagate (int node, int l, int r) {
    if (!lzy[node]) return;
    if (l != r) {
      t[node << 1] = t[node];
      lzy[node << 1] = 1;
      t[node << 1 | 1] = t[node];
      lzy[node << 1 | 1] = 1;
    }
    lzy[node] = 0;
  }
  void update (int node, int l, int r, int x, int y, int i) {
    propagate(node, l, r);
    if (x <= l && r <= y) {
      t[node] = i;
      lzy[node] = 1;
      return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) update(node << 1, l, mid, x, y, i);
    if (y > mid) update(node << 1 | 1, mid + 1, r, x, y, i);
  }
  int query (int node, int l, int r, int x) {
    if (l == r) {
      return t[node];
    }
    propagate(node, l, r);
    int mid = (l + r) >> 1;
    if (x <= mid) return query(node << 1, l, mid, x);
    return query(node << 1 | 1, mid + 1, r, x);
  }
} tree1;

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= n; ++i) scanf("%d", b + i);
  for (int i = 1; i <= m; ++i) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d %d %d", a_pos + i, b_pos + i, len + i);
      tree1.update(1, 1, n, b_pos[i], b_pos[i] + len[i] - 1, i);
    } else {
      int x;
      scanf("%d", &x);
      int q = tree1.query(1, 1, n, x);
      if (!q) {
        printf("%d\n", b[x]);
      } else {
        printf("%d\n", a[x + a_pos[q] - b_pos[q]]);
      }
    }
  }
  return 0;
}
