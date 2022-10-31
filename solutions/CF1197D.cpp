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

const int N = 3e5 + 5;

int n, m, k;
int a[N];
lli p[N];
lli best[N];

lli sum (int l, int r) {
  l = max(0, l - 1);
  if (l > r) return 0;
  return p[r] - p[l];
}

lli get (int i) {
  return i < 0 ? 0 : best[i];
}

int main () {
  scanf("%d %d %d", &n, &m, &k);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
    p[i] = p[i - 1] + a[i];
  }
  lli ans = 0;
  for (int len = 1; len <= m && len <= n; ++len) {
    ans = max(ans, sum(1, len - 1) - 1);
  }
  FOR(i, 1, n + 1) {
    if (i >= m) {
      lli add = sum(i - m + 1, i) - k;
      if (i - m >= 0) add += best[i - m];
      best[i] = max(0ll, add);
      ans = max(ans, best[i]);
    }
    for (int len = 0; len < m && i + len <= n; ++len) {
      ans = max(ans, best[i] + sum(i + 1, i + len) - k * (len > 0));
    }
  }
  printf("%lld\n", ans);
  return 0;
}
