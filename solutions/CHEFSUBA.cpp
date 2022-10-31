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

const int N = 3e5 + 2;

int t[N << 3];
int b[N << 1], a[N];

void build (int lx, int rx, int x) {
  if (lx == rx) {
    t[x] = b[lx];
    return;
  }
  int midx = lx + rx >> 1;
  build(lx, midx, 2 * x);
  build(midx + 1, rx, 2 * x + 1);
  t[x] = max(t[2 * x], t[2 * x + 1]);
}

int query (int lx, int rx, int x, int ql, int qr) {
  if (lx > qr || rx < ql || ql > qr) {
    return -1;
  }
  if (ql <= lx && rx <= qr) {
    return t[x];
  }
  int midx = lx + rx >> 1;
  return max(query(lx, midx, 2 * x, ql, qr), query(midx + 1, rx, 2 * x + 1, ql, qr));
}

void test_case() {
  int n, k, p; cin >> n >> k >> p;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i + n];
    a[i] = a[i + n];
  }
  for (int i = 2 * n; i >= 1; --i) {
    b[i] = b[i + 1] + a[i] - a[i + k];
  }
  build(1, 2 * n, 1);
  string s; cin >> s;
  int pos = n + 1;
  for (auto &e : s) {
    if (e == '!') {
      --pos;
      if (pos == 1) {
        pos = n + 1;
      }
    } else {
      if (k == n) {
        cout << b[n] << '\n';
        continue;
      }
      int l = pos, r = pos + n - k;
      cout << query(1, 2 * n, 1, l, r) << '\n';
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