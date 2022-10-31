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

int a[N];
int n;
int t[N << 2];
map < int, lli > best[N];

int merge (int x, int y) {
  return a[x] < a[y] ? x : y;
}

void build (int lx, int rx, int x) {
  if (lx == rx) {
    t[x] = lx;
    return;
  }
  int midx = lx + rx >> 1;
  build(lx, midx, 2 * x);
  build(midx + 1, rx, 2 * x + 1);
  t[x] = merge(t[2 * x], t[2 * x + 1]);
}

int query (int lx, int rx, int x, int ql, int qr) {
  if (lx > qr || rx < ql) {
    return 0;
  }
  if (ql <= lx && rx <= qr) {
    return t[x];
  }
  int midx = lx + rx >> 1;
  return merge(query(lx, midx, 2 * x, ql, qr), query(midx + 1, rx, 2 * x + 1, ql, qr));
}

lli solve (int l, int r) {
  if (l > r) {
    return 0;
  }
  if (l == r) {
    best[l][r] = a[l];
    return a[l];
  }
  int min_idx = query(1, n, 1, l, r);
  lli ans1 = (min_idx - l + 1) * 1ll * a[min_idx] + solve(min_idx + 1, r);
  lli ans2 = (r - min_idx + 1) * 1ll * a[min_idx] + solve(l, min_idx - 1);
  return best[l][r] = max(ans1, ans2);
}

lli get (int l, int r) {
  if (l > r) {
    return 0;
  }
  return best[l][r];
}

void modify (int l, int r) {
  if (l >= r) {
    return;
  }
  int min_idx = query(1, n, 1, l, r);
  lli ans1 = (min_idx - l + 1) * 1ll * a[min_idx] + get(min_idx + 1, r);
  lli ans2 = (r - min_idx + 1) * 1ll * a[min_idx] + get(l, min_idx - 1);
  if (best[l][r] == ans1) {
    FOR(i, l, min_idx) {
      a[i] = a[min_idx];
    }
    modify(min_idx + 1, r);
  } else {
    FOR(i, min_idx + 1, r + 1) {
      a[i] = a[min_idx];
    }
    modify(l, min_idx - 1);
  }
}

int main () {
  scanf("%d", &n);
  a[0] = 2e9;
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
  }
  build(1, n, 1);
  solve(1, n);
  modify(1, n);
  FOR(i, 1, n + 1) {
    printf("%d ", a[i]);
  }
  return 0;
}
