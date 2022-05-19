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

int main () {
  int n; scanf("%d", &n);
  vector < lli > v(n);
  for (auto &e : v) {
    scanf("%lld", &e);
  }
  sort(all(v));
  lli s = accumulate(all(v), 0ll);
  int m; scanf("%d", &m);
  while (m--) {
    lli x, y; scanf("%lld %lld", &x, &y);
    int idx = lower_bound(all(v), x) - v.begin();
    lli ans = 2e18;
    if (idx > 0) {
      ans = min(ans, x - v[idx - 1] + max(0ll, y - s + v[idx - 1]));
    }
    if (idx < n) {
      ans = min(ans, max(0ll, y - s + v[idx]));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
