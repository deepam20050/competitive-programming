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

const int N = 2e5 + 5;

int a[N], b[N];
int n;

bool f (int x) {
  int c = 0;
  FOR(i, 1, n + 1) {
    if (x - 1 - a[i] <= c && c <= b[i]) {
      ++c;
    }
  }
  return c >= x;
}

void solveTestCase () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d %d", a + i, b + i);
  }
  int l = 1, r = N;
  FOR(i, 0, 19) {
    int midx = l + r >> 1;
    if (f(midx)) {
      l = midx;
    } else {
      r = midx;
    }
  }
  printf("%d\n", l);
}

int main () {
  int _tc; scanf("%d", &_tc);
  while (_tc--) {
    solveTestCase();
  }
  return 0;
}