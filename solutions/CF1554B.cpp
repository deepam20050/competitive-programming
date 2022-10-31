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
  int n, k;
  scanf("%d %d", &n, &k);
  vector < int > a(n + 1);
  FOR(i, 1, n + 1) {
    scanf("%d", &a[i]);
  }
  lli ans = -1e18;
  int start = max(1, n - 2 * k);
  FOR(i, start, n + 1) {
    FOR(j, i + 1, n + 1) {
      ans = max(ans, i * 1ll * j - 1ll * k * (a[i] | a[j]));
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
