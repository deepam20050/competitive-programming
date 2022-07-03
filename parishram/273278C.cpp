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

const int N = 1e5 + 5;

int a[N];
int t[N << 2];

void build (int lx, int rx, int x) {
  if (lx == rx) {
    t[x] = a[lx];
    return;
  }
  int midx = lx + rx >> 1;
  build(lx, midx, 2 * x);
  build(midx + 1, rx, 2 * x + 1);
  t[x] = max(t[2 * x], t[2 * x + 1]);
}

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
  t[x] = max(t[2 * x], t[2 * x + 1]);
}

int find_first_index (int lx, int rx, int x, int val) {
  if (t[x] < val) return -1;
  if (lx == rx) {
    return lx;
  }
  int midx = lx + rx >> 1;
  if (t[2 * x] >= val) {
    return find_first_index(lx, midx, 2 * x, val);
  }
  return find_first_index(midx + 1, rx, 2 * x + 1, val);
}

void test_case() {
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  build(0, n - 1, 1);
  while (m--) {
    int op; cin >> op;
    if (op == 1) {
      int i, v; cin >> i >> v;
      update(0, n - 1, 1, i, v);
    } else {
      int x; cin >> x;
      cout << find_first_index(0, n - 1, 1, x) << '\n';
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