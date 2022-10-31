#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 5;

int arr[N];

struct SegTree {
  long long t[N << 2], lzy[N << 2];
  void build (int node, int l, int r) {
    if (l == r) {
      t[node] = arr[l];
      return;
    }
    int mid = l + r >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    t[node] = min(t[node << 1], t[node << 1 | 1]);
  }
  void propagate (int node, int l, int r) {
    t[node] += lzy[node];
    if (l != r) {
      lzy[node << 1] += lzy[node];
      lzy[node << 1 | 1] += lzy[node];
    }
    lzy[node] = 0;
  }
  void update (int node, int l, int r, int x, int y, int add) {
    propagate(node, l, r);
    if (x <= l && r <= y) {
      lzy[node] += 1ll * add;
      return;
    }
    int mid = l + r >> 1;
    if (x <= mid) {
      update(node << 1, l, mid, x, y, add);
    }
    if (y > mid) {
      update(node << 1 | 1, mid + 1, r, x, y, add);
    }
    propagate(node << 1, l, mid);
    propagate(node << 1 | 1, mid + 1, r);
    t[node] = min(t[node << 1], t[node << 1 | 1]);
  }
  long long query (int node, int l, int r, int x, int y) {
    propagate(node, l, r);
    if (x <= l && r <= y) {
      return t[node];
    }
    int mid = l + r >> 1;
    long long ans = 9e18;
    if (x <= mid) {
      ans = min(ans, query(node << 1, l, mid, x, y));
    }
    if (y > mid) {
      ans = min(ans, query(node << 1 | 1, mid + 1, r, x, y));
    }
    return ans;
  }
} tree1;

int main () {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }
  tree1.build(1, 0, n - 1);
  int nq;
  scanf("%d", &nq);
  getchar();
  while (nq--) {
    char s[100];
    int a = -1, b = -1, c = -1e9;
    scanf("%100[^\n]", s);
    getchar();
    sscanf(s, "%d %d %d", &a, &b, &c);
    if (c == -1e9) {
      if (a <= b) printf("%lld\n", tree1.query(1, 0, n - 1, a, b));
      else {
        auto x1 = tree1.query(1, 0, n - 1, 0, b);
        auto x2 = tree1.query(1, 0, n - 1, a, n - 1);
        printf("%lld\n", min(x1, x2));
      }
    } else {
      if (a <= b) tree1.update(1, 0, n - 1, a, b, c);
      else {
        tree1.update(1, 0, n - 1, 0, b, c);
        tree1.update(1, 0, n - 1, a, n - 1, c);
      }
    }
  }

  return 0;
}
