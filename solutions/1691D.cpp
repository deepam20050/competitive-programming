#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

const lli inf = 1e18;

const int N = 2e5 + 5;

int a[N];
int n;
lli sum[2][N];
int lft[N], rgt[N];

struct SegTree {
  lli t[N << 2];
  void build (int lx, int rx, int x, int who) {
    if (lx == rx) {
      t[x] = sum[who][lx];
      return;
    }
    int midx = lx + rx >> 1;
    build(lx, midx, 2 * x, who);
    build(midx + 1, rx, 2 * x + 1, who);
    t[x] = max(t[2 * x], t[2 * x + 1]);
  }
  lli query (int lx, int rx, int x, int ql, int qr) {
    if (lx > qr || rx < ql || ql > qr) {
      return -inf;
    }
    if (ql <= lx && rx <= qr) {
      return t[x];
    }
    int midx = lx + rx >> 1;
    return max(query(lx, midx, 2 * x, ql, qr), query(midx + 1, rx, 2 * x + 1, ql, qr));
  }
};

SegTree pref_max, suff_max;

void solveTestCase () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
    sum[0][i] = sum[0][i - 1] + 1ll * a[i];
  }
  sum[1][n] = a[n];
  for (int i = n - 1; i >= 1; --i) {
    sum[1][i] = sum[1][i + 1] + 1ll * a[i];
  }
  stack < int > s;
  FOR(i, 1, n + 1) {
    while (!s.empty() && a[s.top()] <= a[i]) {
      s.pop();
    }
    lft[i] = s.empty() ? 1 : s.top() + 1;
    s.em(i);
  }
  while (!s.empty()) s.pop();
  for (int i = n; i >= 1; --i) {
    while (!s.empty() && a[s.top()] <= a[i]) {
      s.pop();
    }
    rgt[i] = s.empty() ? n : s.top() - 1;
    s.em(i);
  }
  pref_max.build(1, n, 1, 0);
  suff_max.build(1, n, 1, 1);
  FOR(i, 1, n + 1) {
    lli left_max = suff_max.query(1, n, 1, lft[i], i - 1) - sum[1][i];
    lli right_max = pref_max.query(1, n, 1, i + 1, rgt[i]) - sum[0][i];
    if (max(left_max, right_max) > 0) {
      puts("NO");
      return;
    }
  }
  puts("YES");
}

int main () {
  int _tc; scanf("%d", &_tc);
  while (_tc--) {
    solveTestCase();
  }
  return 0;
}