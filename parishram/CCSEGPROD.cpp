// AC
#include "bits/stdc++.h"

using namespace std;

const int N = 1e6 + 5;
const int LN = 21;
const int M = 1 << LN;

int a[M];
int b[N];
int n, p, q;

struct DisjointSparseTable {
  int st[LN][M];
  int query (int l, int r) {
    if (l == r) return a[l];
    int lg = __lg(l ^ r);
    return st[lg][l] * 1ll * st[lg][r] % p;
  }
  void build (int lg, int l, int r) {
    if (lg < 0) return;
    int m = l + r >> 1;
    for (int i = m - 1; i >= l; --i) {
      st[lg][i] = a[i] * 1ll * (i == m - 1 ? 1 : st[lg][i + 1]) % p;
    }
    for (int i = m; i <= r; ++i) {
      st[lg][i] = a[i] * 1ll * (i == m ? 1 : st[lg][i - 1]) % p;
    }
    build(lg - 1, l, m);
    build(lg - 1, m, r);
  }
} disj_sparse;

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d %d %d", &n, &p, &q);
    int k = n == 1 ? 0 : __lg(n - 1) + 1;
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int j = 0, sz = q / 64 + 2; j < sz; ++j) scanf("%d", b + j);
    disj_sparse.build(k - 1, 0, 1 << k);
    int x = 0, l, r;
    for (int i = 0; i < q; ++i) {
      if (i % 64 == 0) {
        l = (b[i / 64] + x) % n;
        r = (b[i / 64 + 1] + x) % n;
      } else {
        l = (l + x) % n;
        r = (r + x) % n;
      }
      if (l > r) swap(l, r);
      x = (disj_sparse.query(l, r) + 1) % p;
    }
    printf("%d\n", x);
  }
  return 0;
}
