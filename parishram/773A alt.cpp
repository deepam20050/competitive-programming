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

lli ceil (lli x, lli y) {
  return (x + y - 1) / y;
}

void solveTestCase () {
  scanf("%lld %lld %lld %lld", &x, &y, &p, &q);
  if (q - p == 0) {
    y - x != 0 ? puts("-1") : puts("0");
    return;
  }
  if (p == 0) {
    x ? puts("-1") : puts("0");
    return;
  }
  lli t = max(ceil(x, p), ceil(y - x, q - p));
  printf("%lld\n", t * q - y);
}

int main () {
  int _tc; scanf("%d", &_tc);
  while (_tc--) {
    solveTestCase();
  }
  return 0;
}