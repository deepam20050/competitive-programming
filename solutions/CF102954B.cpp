#include "bits/stdc++.h"

using namespace std;

const int MOD = 764854400;
const int LM = 21;
const int M = 1 << LM;
const int N = 1e6 + 5;

int a[N];

struct DisjointSparseTable {
  int st[LM][M];
  int query (int l, int r) {
    if (l == r) return a[l];
    int lg = __lg(l ^ r);
    return st[lg][l] * 1ll * st[lg][r] % MOD;
  }
  void build (int lg, int l, int r) {
    if (lg < 0) return;
    int m = l + r >> 1;
    for (int i = m - 1; i >= l; --i) {
      st[lg][i] = a[i] * 1ll * (i == m - 1 ? 1 : st[lg][i + 1]) % MOD;
    }
    for (int i = m; i <= r; ++i) {
      st[lg][i] = a[i] * 1ll * (i == m ? 1 : st[lg][i - 1]) % MOD;
    }
    build(lg - 1, l, m);
    build(lg - 1, m, r);
  }
} disj_sparse;

int main () {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  int k = n == 1 ? 0 : __lg(n - 1) + 1;
  disj_sparse.build(k - 1, 1, (1 << k) - 1);
  int nq;
  scanf("%d", &nq);
  while (nq--) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", disj_sparse.query(l, r));
  }
  return 0;
}