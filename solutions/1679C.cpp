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

using lli = int64_t;
using pii = pair < int, int >;

const int N = 1e5 + 5;

int n, nq;
int row_cnt[N], col_cnt[N];

struct FenwickTree {
  vector < int > t;
  int n;
  FenwickTree (int siz) : n(siz) {
    t.assign(n + 2, 0);
  }  
  void update (int idx, int x) {
    while (idx <= n) {
      t[idx] += x;
      idx += idx & -idx;
    }
  }
  int query (int idx) {
    int ret = 0;
    while (idx > 0) {
      ret += t[idx];
      idx -= idx & -idx;
    }
    return ret;
  }
};

void test_case() {
  cin >> n >> nq;
  FenwickTree row(n + 1), col(n + 1);
  while (nq--) {
    int op; cin >> op;
    if (op == 1 || op == 2) {
      int x, y; cin >> x >> y;
      int add = op == 1 ? 1 : -1;
      int who = op == 1 ? 1 : 0;
      row_cnt[x] += add;
      col_cnt[y] += add;
      if (row_cnt[x] == who) {
        row.update(x, add);
      }
      if (col_cnt[y] == who) {
        col.update(y, add);
      }
    }
    if (op == 3) {
      int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
      int r = row.query(x2) - row.query(x1 - 1);
      int c = col.query(y2) - col.query(y1 - 1);
      debug(c);
      (r == x2 - x1 + 1) || (c == y2 - y1 + 1) ? cout << "Yes\n" : cout << "No\n";
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