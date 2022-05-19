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
  int n, m;
  scanf("%d %d", &n, &m);
  if (n > m) {
    swap(n, m);
  }
  if (n == 1 && m == 1) {
    puts("0");
    return;
  }
  if (n == 1 && m == 2) {
    puts("1");
    return;
  }
  if (n == 1 || m == 1) {
    puts("-1");
    return;
  }
  if (n == m) {
    printf("%d\n", 2 * n - 2);
    return;
  }
  int x = m - n + 1;
  lli ans = 2ll * (n - 1);
  if (x & 1) {
    ans += 2ll * (x - 1);
  } else {
    ans += 2ll * x - 3ll;
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
