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

using lli = long long;
using pii = pair < int, int >;

const int N = 5e5 + 5;

int t[4 * N];
int a[N];
int mx_val;
int xx;
int bad;

void build (int lx, int rx, int x) {
  if (lx == rx) {
    t[x] = a[lx];
    mx_val = max(mx_val, x + 1);
    return;
  }
  int midx = lx + rx >> 1;
  build(lx, midx, 2 * x);
  build(midx + 1, rx, 2 * x + 1);
  t[x] = __gcd(t[2 * x], t[2 * x + 1]);
}

void update (int lx, int rx, int x, int i, int val) {
  if (lx == rx) {
    t[x] = val;
    return;
  }
  int midx = lx + rx >> 1;
  if (i <= midx) {
    update(lx, midx, 2 * x, i, val);
  } else {
    update(midx + 1, rx, 2 * x + 1, i, val);
  }
  t[x] = __gcd(t[2 * x], t[2 * x + 1]);
}

void query (int lx, int rx, int x, int ql, int qr) {
  if (lx > qr || rx < ql || lx > rx) {
    return;
  }
  if (ql <= lx && rx <= qr) {
    if (t[x] % xx == 0) {
      return;
    }
    while (x < (N * 2)) {
      if (t[2 * x] % xx) {
        if (t[2 * x + 1] % xx) {
          bad += 2;
          return;
        }
        x = 2 * x;
      } else {
        x = 2 * x + 1;
      }
    }
    ++bad;
    return;
  }
  int midx = lx + rx >> 1;
  query(lx, midx, 2 * x, ql, qr);
  query(midx + 1, rx, 2 * x + 1, ql, qr);
}

int main () {
  int n;
  scanf("%d", &n);
  FOR(i, 0, n) {
    scanf("%d", a + i + 1);
  }
  build(1, n, 1);
  int nq;
  scanf("%d", &nq);
  while (nq--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int l, r;
      scanf("%d %d %d", &l, &r, &xx);
      bad = 0;
      query(1, n, 1, l, r);
      bad <= 1 ? puts("YES") : puts("NO");
    } else {
      int i, y;
      scanf("%d %d", &i, &y);
      update(1, n, 1, i, y);
    }
  }
  return 0;
}
