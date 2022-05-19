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
  lli n; scanf("%lld", &n);
  lli ans = n;
  FOR(i, 1, 1 << 9) {
    int x = -1;
    FOR(j, 0, 9) {
      if (i >> j & 1) {
        if (x == -1) x = j + 2;
        x = x / __gcd(j + 2, x) * (j + 2);
      }
    }
    ans = ans + (__builtin_popcount(i) & 1 ? -1 : 1) * n / x;
  }
  printf("%lld\n", ans);
  return 0;
}