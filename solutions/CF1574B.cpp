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
  int a, b, c, m; scanf("%d %d %d %d", &a, &b, &c, &m);
  vector < int > arr = {a, b, c};
  sort(all(arr));
  a = arr[0]; b = arr[1]; c = arr[2];
  c - 1 - a - b <= m && m <= a + b + c - 3 ? puts("YES") : puts("NO");
}

int main () {
  int _tc; scanf("%d", &_tc);
  while (_tc--) {
    solveTestCase();
  }
  return 0;
}
