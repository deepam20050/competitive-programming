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

const int N = 305;

void solveTestCase () {
  int n, m; scanf("%d %d", &n, &m);
  vector < pii > v(n * m);
  FOR(i, 0, n * m) {
    scanf("%d", &v[i].F);
    v[i].S = i;
  }
  sort(all(v));
  FOR(i, 0, n * m) {
    v[i].S = -v[i].S;
  }
  int ans = 0;
  FOR(i, 0, n) {
    sort(v.begin() + i * m, v.begin() + (i + 1) * m);
    FOR(j, 0, m) {
      FOR(k, 0, j) {
        ans += -v[i * m + k].S < -v[i * m + j].S;
      }
    }
  }
  printf("%d\n", ans);
}

int main () {
  int _tc; scanf("%d", &_tc);
  while (_tc--) {
    solveTestCase();
  }
  return 0;
}