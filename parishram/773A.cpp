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

lli x, y, p, q;

bool f (lli t) {
  return p * t >= x && (q - p) * t >= y - x;
}

void solveTestCase () {
  scanf("%lld %lld %lld %lld", &x, &y, &p, &q);
  lli l = 0, r = 1e9;
  if (!f(r)) {
    puts("-1");
    return;
  }
  FOR(i, 0, 30) {
    lli midx = l + r >> 1ll;
    if (f(midx)) {
      r = midx;
    } else {
      l = midx;
    }
  }
  printf("%lld\n", r * q - y);
}

int main () {
  int _tc; scanf("%d", &_tc);
  while (_tc--) {
    solveTestCase();
  }
  return 0;
}