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

using lli = long long;
using pii = pair < int, int >;

const int N = 2e5 + 5;

int a[N];
int t[N << 2];
int pos[N];
int ans[N];

void update (int lx, int rx, int x, int pos, int val) {
  if (lx == rx) {
    t[x] = val;
    return;
  }
  int midx = lx + rx >> 1;
  if (pos <= midx) {
    update(lx, midx, 2 * x, pos, val);
  } else {
    update(midx + 1, rx, 2 * x + 1, pos, val);
  }
  t[x] = t[2 * x] + t[2 * x + 1];
}

int query (int lx, int rx, int x, int ql, int qr) {
  if (lx > qr || ql > rx) {
    return 0;
  }
  if (ql <= lx && rx <= qr) {
    return t[x];
  }
  int midx = lx + rx >> 1;
  return query(lx, midx, 2 * x, ql, qr) + query(midx + 1, rx, 2 * x + 1, ql, qr);
}

void test_case() {
  int n; cin >> n;
  memset(pos, -1, sizeof pos);
  for (int i = 0; i < 2 * n; ++i) {
    cin >> a[i];
    if (pos[a[i]] == -1) {
      pos[a[i]] = i;
    }
  }
  for (int i = 0; i < 2 * n; ++i) {
    if (pos[a[i]] != i) {
      update(0, 2 * n - 1, 1, pos[a[i]], 1);
      ans[a[i]] = query(0, 2 * n - 1, 1, pos[a[i]], i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] - 1 << " \n"[i == n];
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