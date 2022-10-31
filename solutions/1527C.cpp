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
  int n; scanf("%d", &n);
  vector < pii > v(n);
  FOR(i, 1, n + 1) {
    int x; scanf("%d", &x);
    v[i - 1] = {x, i};
  }
  sort(all(v));
  lli ans = 0, sum = 0;
  FOR(i, 0, n) {
    int j = i;
    while (j < n && v[j].F == v[i].F) {
      sum += 1ll * (n - v[j].S + 1);
      ++j;
    }
    FOR(k, i, j) {
      sum -= 1ll * (n - v[k].S + 1);
      ans += sum * v[k].S;
    }
    i = j - 1;
  }
  printf("%lld\n", ans);
}

int main () {
  int _tc; scanf("%d", &_tc);
  while (_tc--) {
    solveTestCase();
  }
  return 0;
}