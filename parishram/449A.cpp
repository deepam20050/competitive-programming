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

int n, m, k;

lli f (lli x, lli y) {
  if (x < 1 || y < 1) {
    return -1;
  }
  return max((n / x) * (m / y), (n / y) * (m / x));
}

int main () {
  scanf("%d %d %d", &n, &m, &k);
  if (n + m - 2 < k) {
    puts("-1");
    exit(0);
  }
  if (n < m) {
    swap(n, m);
  }
  lli ans = -1;
  for (int i = 1; i * 1ll * i <= n; ++i) {
    ans = max(ans, f(i, k + 2 - i));
    ans = max(ans, f(n / i, k + 2 - n / i));
  }
  printf("%lld\n", ans);
  return 0;
}