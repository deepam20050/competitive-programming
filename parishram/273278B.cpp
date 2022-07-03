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
  t[x] = t[2 * x] + t[2 * x + 1];
}

void update (int lx, int rx, int x, int pos) {
  if (lx == rx) {
    t[x] = a[lx];
    return;
  }
  int midx = lx + rx >> 1;
  if (pos <= midx) {
    update(lx, midx, 2 * x, pos);
  } else {
    update(midx + 1, rx, 2 * x + 1, pos);
  }
  t[x] = t[2 * x] + t[2 * x + 1];
}

int find_kth_one (int lx, int rx, int x, int k) {
  if (lx == rx) {
    return lx;
  }
  int midx = lx + rx >> 1;
  return t[2 * x] < k ? find_kth_one(midx + 1, rx, 2 * x + 1, k - t[2 * x]) : find_kth_one(lx, midx, 2 * x, k);
}

void test_case() {
  int n, nq; cin >> n >> nq;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  build(0, n - 1, 1);
  while (nq--) {
    int op; cin >> op;
    if (op == 1) {
      int i; cin >> i;
      a[i] ^= 1;
      update(0, n - 1, 1, i);
    } else {
      int k; cin >> k;
      cout << find_kth_one(0, n - 1, 1, k + 1) << '\n';
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