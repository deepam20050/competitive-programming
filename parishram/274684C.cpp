// AC
#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 5;
const int M = 41;

int arr[N];

struct node_data {
  long long ans;
  long long cnt[M + 1];
  node_data () {
    ans = 0;
    memset(cnt, 0, sizeof cnt);
  }
};

struct SegTree {
  node_data t[N << 2];
  node_data combine (const node_data &L, const node_data &R) {
    node_data ret;
    ret.ans = L.ans + R.ans;
    for (int i = 1; i < M; ++i) {
      ret.ans += 1ll * (L.cnt[i] - L.cnt[i - 1]) * R.cnt[i - 1];
    }
    for (int i = 1; i < M; ++i) {
      ret.cnt[i] = ret.cnt[i - 1] + (L.cnt[i] - L.cnt[i - 1]) + (R.cnt[i] - R.cnt[i - 1]);
    }
    return ret;
  }
  void build (int node, int l, int r) {
    if (l == r) {
      t[node].cnt[arr[l]] = 1;
      for (int i = 1; i < M; ++i) {
        t[node].cnt[i] += t[node].cnt[i - 1];
      }
      t[node].ans = 0;
      return;
    }
    int mid = l + r >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    t[node] = combine(t[node << 1], t[node << 1 | 1]);
  }
  void update (int node, int l, int r, int x, int y) {
    if (l == r) {
      memset(t[node].cnt, 0, sizeof t[node].cnt);
      t[node].cnt[y] = 1;
      for (int i = 1; i < M; ++i) {
        t[node].cnt[i] += t[node].cnt[i - 1];
      }
      t[node].ans = 0;
      return;
    }
    int mid = l + r >> 1;
    if (x <= mid) {
      update(node << 1, l, mid, x, y);
    } else {
      update(node << 1 | 1, mid + 1, r, x, y);
    }
    t[node] = combine(t[node << 1], t[node << 1 | 1]);
  }
  node_data query (int node, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
      return t[node];
    }
    int mid = l + r >> 1;
    node_data ret;
    if (x <= mid) {
      ret = combine(ret, query(node << 1, l, mid, x, y));
    } 
    if (y > mid) {
      ret = combine(ret, query(node << 1 | 1, mid + 1, r, x, y));
    }
    return ret;
  }
};

SegTree tree1;

int main () {
  int n, nq;
  scanf("%d %d", &n, &nq);
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }
  tree1.build(1, 0, n - 1);
  while (nq--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == 1) {
      printf("%lld\n", tree1.query(1, 0, n - 1, b - 1, c - 1).ans);
    } else {
      tree1.update(1, 0, n - 1, b - 1, c);
    }
  }
  return 0;
}