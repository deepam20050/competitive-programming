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

typedef long long lli;
typedef pair < int, int > pii;

const int N = 2e5 + 5;

vector < int > t[N << 2];
int a[N];
int n;

void build (int lx, int rx, int x) {
  if (lx == rx) {
    t[x] = {a[lx]};
    return;
  }
  int midx = lx + rx >> 1;
  build(lx, midx, 2 * x);
  build(midx + 1, rx, 2 * x + 1);
  merge(all(t[2 * x]), all(t[2 * x + 1]), std::back_inserter(t[x]));
}

int query (int lx, int rx, int x, int ql, int qr, int val) {
  if (lx > qr || rx < ql) {
    return 0;
  }
  if (ql <= lx && rx <= qr) {
    return upper_bound(all(t[x]), val) - lower_bound(all(t[x]), val);
  }
  int midx = lx + rx >> 1;
  return query(lx, midx, 2 * x, ql, qr, val) + query(midx + 1, rx, 2 * x + 1, ql, qr, val);
}

void test_case() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  build(0, n - 1, 1);
  int nq; cin >> nq;
  while (nq--) {
    int l, r, val; cin >> l >> r >> val;
    cout << query(0, n - 1, 1, l - 1, r - 1, val) << '\n';
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