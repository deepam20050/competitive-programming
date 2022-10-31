// AC
#include "bits/stdc++.h"

using namespace std;

const int N = 5005;
const int LN = 14;

int a[N];
int n;

struct SparseTable {
  int st[LN][N];
  void build () {
    for (int i = 1; i <= n; ++i) {
      st[0][i] = i;
    }
    iota(st[0], st[0] + n + 1, 0);
    for (int i = 1; i < LN; ++i) {
      for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
        int idx1 = st[i - 1][j];
        int idx2 = st[i - 1][j + (1 << (i - 1))];
        st[i][j] = a[idx1] <= a[idx2] ? idx1 : idx2;
      }
    }
  }
  int query (int l, int r) {
    int t = __lg(r - l + 1);
    int idx1 = st[t][l];
    int idx2 = st[t][r - (1 << t) + 1];
    return a[idx1] <= a[idx2] ? idx1 : idx2;
  }
} tree1;


int solve (int l, int r, int del = 0) {
  if (l > r) return 0;
  int idx = tree1.query(l, r);
  int add = a[idx] - del;
  return min(add + solve(l, idx - 1, del + add) + solve(idx + 1, r, del + add), r - l + 1);
}

int main () {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  tree1.build();
  printf("%d\n", solve(1, n));  
  return 0;
}