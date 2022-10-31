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

int pref[N];
int a[N];

struct Node {
  map < int, int > cnt;
};

Node t[N << 2];

void build (int lx, int rx, int x) {
  if (lx == rx) {
    ++t[x].cnt[pref[lx]];
    return;
  }
  int midx = lx + rx >> 1;
  build(lx, midx, 2 * x);
  build(midx + 1, rx, 2 * x + 1);
  t[x].cnt = t[2 * x].cnt;
  for (auto [val, c] : t[2 * x + 1].cnt) {
    t[x].cnt[val] += c;
  }
}

int query (int lx, int rx, int x, int ql, int qr, int k) {
  if (lx > qr || ql > rx) {
    return 0;
  }
  if (lx <= ql && qr <= rx) {
    return t[x].cnt[k];
  }
  int midx = lx + rx >> 1;
  return query(lx, midx, 2 * x, ql, qr, k) + query(midx + 1, rx, 2 * x + 1, ql, qr, k);
}

// op = 0 delete
// op = 1 insert
void update (int lx, int rx, int x, int pos, int val, int op) {
  if (lx == rx) {
    op ? t[x].cnt[val]++ : t[x].cnt[val]--; 
    return;
  }
  int midx = lx + rx >> 1;
  if (pos <= midx) {
    update(lx, midx, 2 * x, pos, val, op);
  }
  if (pos > midx) {
    update(midx + 1, rx, 2 * x + 1, pos, val, op);
  }
  op ? t[x].cnt[val]++ : t[x].cnt[val]--;
}

void test_case() {
  int n, nq; cin >> n >> nq;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pref[i] = pref[i - 1] ^ a[i];
  }
  build(1, n, 1);
  while (nq--) {
    int type, i, x; cin >> type >> i >> x;
    if (type == 1) {
      update(1, n, 1, i, pref[i], 0);
      pref[i] ^= a[i] ^ x;
      a[i] = x;
      update(1, n, 1, i, pref[i], 1);
    } else {
      cout << query(1, n, 1, 1, i, x) << '\n';
    }
  } 
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}