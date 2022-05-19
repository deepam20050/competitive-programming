#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 5;

struct data {
  int gcd, min, cnt;
  data () {
    gcd = 0;
    min = 2e9;
    cnt = 0;
  }
};

int a[N];
int n;

struct SegTree {
  data t[N << 2];
  data join (const data &L, const data &R) {
    data ret;
    ret.gcd = __gcd(L.gcd, R.gcd);
    ret.min = min({L.min, R.min});
    ret.cnt = (L.min == ret.min) * L.cnt;
    ret.cnt += (R.min == ret.min) * R.cnt;
    return ret;
  }
  void build (int node, int l, int r) {
    if (l == r) {
      t[node].gcd = a[l];
      t[node].min = a[l];
      t[node].cnt = 1;
      return;
    }
    int mid = (l + r) >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    t[node] = join(t[node << 1], t[node << 1 | 1]);
  }
  data query (int node, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
      return t[node];
    }
    int mid = (l + r) >> 1;
    data ret;
    if (x <= mid) {
      ret = join(ret, query(node << 1, l, mid, x, y));
    }
    if (y > mid) {
      ret = join(ret, query(node << 1 | 1, mid + 1, r, x, y));
    }
    return ret;
  }
};

SegTree tree1;

int main () {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  tree1.build(1, 1, n);
  int nq;
  scanf("%d", &nq);
  while (nq--) {
    int l, r;
    scanf("%d %d", &l, &r);
    auto ans = tree1.query(1, 1, n, l, r);
    if (ans.gcd == ans.min) {
      printf("%d\n", r - l + 1 - ans.cnt);
    } else {
      printf("%d\n", r - l + 1);
    }
  }
  return 0;
}
