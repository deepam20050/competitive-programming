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

void solve () {
  set < int > st[2];
  map < int, int > cnt[2];
  map < pii, int > del[2];
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  FOR(i, 0, n) {
    int x; scanf("%d", &x);
    st[0].em(x);
  }
  FOR(i, 0, m) {
    int y; scanf("%d", &y);
    st[1].em(y);
  }
  FOR(i, 0, k) {
    int xx, yy; scanf("%d %d", &xx, &yy);
    if (!st[0].count(xx)) {
      auto it = --(st[0].lower_bound(xx));
      ++cnt[0][*it];
      ++del[0][{*it, yy}];
    }
    if (!st[1].count(yy)) {
      auto it = --(st[1].lower_bound(yy));
      ++cnt[1][*it];
      ++del[1][{*it, xx}];
    }
  }
  lli ans = 0;
  FOR(_, 0, 2) {
    for (auto [ignore, cc] : cnt[_]) {
      ans += cc * 1ll * (cc - 1) >> 1ll;
    }
    for (auto [ignore, cc] : del[_]) {
      ans -= cc * 1ll * (cc - 1) >> 1ll;
    }
  }
  printf("%lld\n", ans);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
