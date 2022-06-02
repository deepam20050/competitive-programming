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

const int N = 505;

int a[N];
int n, x;

void solveTestCase () {
  scanf("%d %d", &n, &x);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
  }
  int ans = 0;
  while (true) {
    if (is_sorted(a + 1, a + n + 1)) {
      break;
    }
    int i = 1;
    while (i <= n && a[i] <= x) {
      ++i;
    }
    if (i == n + 1) {
      puts("-1");
      return;
    }
    swap(a[i], x);
    ++ans;
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