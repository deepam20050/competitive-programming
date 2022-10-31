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

struct Node {
  int g, mino, cnt;
  Node () {}
  Node (int a, int b, int c) {
    g = a;
    mino = b;
    cnt = c;
  }
};

int a[N];
Node t[N << 2];

Node merge (const Node &l, const Node &r) {
  Node ret = {gcd(l.g, r.g), min(l.mino, r.mino), 0};
  ret.cnt += (ret.mino == l.mino) * l.cnt;
  ret.cnt += (ret.mino == r.mino) * r.cnt;
  return ret;
}

void build (int lx, int rx, int x) {
  if (lx == rx) {
    t[x] = {a[lx], a[lx], 1};
    return;
  }
  int midx = lx + rx >> 1;
  build(lx, midx, 2 * x);
  build(midx + 1, rx, 2 * x + 1);
  t[x] = merge(t[2 * x], t[2 * x + 1]);
}

Node query (int lx, int rx, int x, int ql, int qr) {
  if (lx > qr || ql > rx) {
    return Node(0, (int)2e9, 0);
  }
  if (ql <= lx && rx <= qr) {
    return t[x];
  }
  int midx = lx + rx >> 1;
  return merge(query(lx, midx, 2 * x, ql, qr), query(midx + 1, rx, 2 * x + 1, ql, qr));
}

void test_case() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  build(1, n, 1);
  int nq; cin >> nq;
  while (nq--) {
    int l, r; cin >> l >> r;
    auto x = query(1, n, 1, l, r);
    int ans = r - l + 1 - (x.g == x.mino) * x.cnt;
    cout << ans << '\n';
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