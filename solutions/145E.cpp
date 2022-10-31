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

const int N = 1e6 + 5;

struct node {
  int four, seven, incr, decr;
};

const node none = {0, 0, 0, 0};

node join (const node &a, const node &b) {
  node ret = {a.four + b.four, a.seven + b.seven, 0, 0};
  ret.incr = max({a.incr, b.incr, ret.four, ret.seven, a.incr + b.seven, a.four + b.incr});
  ret.decr = max({a.decr, b.decr, ret.four, ret.four, a.seven + b.decr, a.decr + b.four});
  return ret;
}

node t[N << 2];
int lazy[N << 2];
string a;

void build (int lx, int rx, int x) {
  if (lx == rx) {
    t[x] = {a[lx] == '4', a[lx] == '7', 1, 1};
    return;
  }
  int midx = lx + rx >> 1;
  build(lx, midx, 2 * x);
  build(midx + 1, rx, 2 * x + 1);
  t[x] = join(t[2 * x], t[2 * x + 1]);
}

void push (int lx, int rx, int x) {
  if (!lazy[x]) return;
  if (lazy[x] & 1) {
    swap(t[x].four, t[x].seven);
    swap(t[x].incr, t[x].decr);
  }
  if (lx != rx) {
    lazy[2 * x] += lazy[x];
    lazy[2 * x + 1] += lazy[x];
  }
  lazy[x] = 0;
}

void update (int lx, int rx, int x, int ql, int qr) {
  push(lx, rx, x);
  if (lx > qr || ql > rx) return;
  if (ql <= lx && rx <= qr) {
    lazy[x] += 1;
    push(lx, rx, x);
    return;
  }
  int midx = lx + rx >> 1;
  update(lx, midx, 2 * x, ql, qr);
  update(midx + 1, rx, 2 * x + 1, ql, qr);
  t[x] = join(t[2 * x], t[2 * x + 1]);
}

node query (int lx, int rx, int x, int ql, int qr) {
  push(lx, rx, x);
  if (lx > qr || ql > rx) return none;
  if (ql <= lx && rx <= qr) {
    return t[x];
  }
  int midx = lx + rx >> 1;
  return join(query(lx, midx, 2 * x, ql, qr), query(midx + 1, rx, 2 * x + 1, ql, qr));
}

void test_case() {
  int n, nq; cin >> n >> nq;
  cin >> a;
  build(0, n - 1, 1);
  while (nq--) {
    string op; cin >> op;
    if (op[0] == 'c') {
      cout << query(0, n - 1, 1, 0, n - 1).incr << '\n';
    } else {
      int l, r; cin >> l >> r;
      update(0, n - 1, 1, l - 1, r - 1);
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