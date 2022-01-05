#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

using lli = long long;

const int MOD = 764854400;
const int LM = 21;
const int M = 1 << LM;
const int N = 1e6 + 5;

int a[N];

struct data {
  int val, cnt;
  data (int _val = 0, int _cnt = 0) {
    val = _val;
    cnt = _cnt;
  }
  data operator+ (const data &other) const {
    data result;
    result.val = max(this.val, other.val);
    result.cnt = this.cnt * (this.val == result.val) + other.cnt * (other.val == result.val);
    return result;
  }
};

struct DisjointSparseTable {
  data st[LM][M];
  int query (int l, int r) {
    if (l == r) return a[l];
    int lg = __lg(l ^ r);
    return st[lg][l] + st[lg][r];
  }
  void build (int lg, int l, int r) {
    if (lg < 0) return;
    int m = l + r >> 1;
    st[lg][m - 1] = {a[n - 1], 1};
    for (int i = m - 2; i >= l; --i) {
      st[lg][i] = data(a[i], 1) + st[lg][i + 1];
    }
    st[lg][m] = {a[m], 1};
    for (int i = m + 1; i <= r; ++i) {
      st[lg][i] = data(a[i], 1) + st[lg][i - 1];
    }
    build(lg - 1, l, m);
    build(lg - 1, m, r);
  }
} disj_sparse;


int main () {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  int q, x, y, z, t;
  scanf("%d %d %d %d %d", &q, &x, &y, &z, &t);
  int x = 0;
  int ans = 1;
  while (q--) {
    int l = (x * )
  }
  return 0;
}