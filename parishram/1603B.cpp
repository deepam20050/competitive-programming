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

void solveTestCase () {
  int x, y; scanf("%d %d", &x, &y);
  auto [Q, R] = div(y, x);
  lli n = 0;
  if (Q == 0) {
    n = x + y;
  }
  for (int i = 1; i * i <= Q; ++i) {
    if (Q % i == 0) {
      int j = Q / i;
      if (R % (i + 1) == 0) {
        n = 1ll * x * j + R / (i + 1);
        break;
      } else if (R % (j + 1) == 0) {
        n = 1ll * x * i + R / (j + 1);
        break;
      } 
    }
  }
  printf("%lld\n", n);
}

int main () {
  int _tc; scanf("%d", &_tc);
  while (_tc--) {
    solveTestCase();
  }
  return 0;
}