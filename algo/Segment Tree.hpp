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

// 1 based indexing
template < typename T >
struct SegmentTree {
  vector < T > t;
  // vector < T > lazy;
  T none_exist;
  int n;
  SegmentTree (T none_, const vector < T > &a) {
    n = sz(a); t.reserve(n << 2);t.resize(n << 2);
    fill(all(t), none_exist);
    none_exist = none_;
    build(a, 1, n - 1, 1);
  }
  void push (int lx, int rx, int x) {
    if (lx > rx) return;
  }
  T merge (const T &L, const T &R) {

  }
  void build (const vector < T > &a, int lx, int rx, int x) {
    if (lx > rx) return;
    if (lx == rx) {
      t[x] = a[lx];
      return;
    }
    int midx = lx + (rx - lx >> 1);
    build(a, lx, midx, 2 * x);
    build(a, midx + 1, rx, 2 * x + 1);
    t[x] = merge(t[2 * x], t[2 * x + 1]);
  }
  T query (int lx, int rx, int x, int ql, int qr) {
    if (lx > qr || rx < ql || ql > qr) {
      return none_exist;
    }
    if (ql <= lx && rx <= qr) {
      return t[x];
    }
    int midx = lx + (rx - lx >> 1);
    return merge(query(lx, midx, 2 * x, ql, qr), query(midx + 1, rx, 2 * x + 1, ql, qr));
  }
  void point_update (int lx, int rx, int x, int idx, T val) {
    if (lx == rx) {
      t[x] = val;
      return;
    }
    int midx = lx + (rx - lx >> 1);
    if (idx <= midx) point_update(lx, midx, 2 * x, idx, val);
    else point_update(midx + 1, rx, 2 * x + 1, idx, val);
    t[x] = merge(t[2 * x], t[2 * x + 1]);
  }
  void range_update (int lx, int rx, int x, int ql, int qr, T val) {
    push(lx, rx, x);
    if (lx > qr || rx < ql || ql > qr) {
      return;
    }
    if (ql <= lx && rx <= qr) {
      // code
    }
    int midx = lx + (rx - lx >> 1);
    range_update(lx, midx, 2 * x, ql, qr, val);
    range_update(midx + 1, rx, 2 * x + 1, ql, qr, val);
  }
};

int main () {
  return 0;
}