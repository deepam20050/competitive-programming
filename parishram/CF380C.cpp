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

const int N = 1e6 + 5;

struct Node {
  int open, close, len;
};

char s[N];
Node t[N << 2];

Node unite (const Node &L, const Node &R) {
  Node ret = {L.open + R.open, L.close + R.close, 0};
  ret.len = L.len + R.len + min(L.open - L.len / 2, R.close - R.len / 2) * 2;
  return ret;
}

void build (int lx, int rx, int x) {
  if (lx == rx) {
    t[x].open = s[lx] == '(';
    t[x].close = s[lx] == ')';
    t[x].len = 0;
    return;
  }
  int midx = lx + rx >> 1;
  build(lx, midx, 2 * x);
  build(midx + 1, rx, 2 * x + 1);
  t[x] = unite(t[2 * x], t[2 * x + 1]);
}

Node query (int lx, int rx, int x, int ql, int qr) {
  if (rx < ql || lx > qr || lx > rx) {
    return Node();
  }
  if (ql <= lx && rx <= qr) {
    return t[x];
  }
  int midx = lx + rx >> 1;
  return unite(query(lx,  midx, 2 * x, ql, qr), query(midx + 1, rx, 2 * x + 1, ql, qr));
}

int main () {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  build(1, n, 1);
  int nq;
  scanf("%d", &nq);
  while (nq--) {
    int l, r;
    scanf("%d %d", &l, &r);
    auto ret = query(1, n, 1, l, r);
    printf("%d\n", ret.len);
  }
  return 0;
}
