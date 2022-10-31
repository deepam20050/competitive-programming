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
  lli n, p; scanf("%lld %lld", &n, &p);
  FOR(m, 1, 1 << 20) {
    lli x = n - m * p;
    if (x <= 0) continue;
    int c = 0, c2 = 0;
    FOR(i, 0, 64) {
      if (i == 0) {
        c += x >> i & 1ll;
        c2 += x >> i & 1ll;
      } else {
        c += i * (x >> i & 1ll);
        c2 += x >> i & 1ll;
      }
    }
    if (c2 <= m && m <= c) {
      printf("%d\n", m);
      exit(0);
    }
  }
  puts("-1");
  return 0;
}