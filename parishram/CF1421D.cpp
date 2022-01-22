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

lli c[7];

lli b (lli x) {
  return x <= 0 ? -x * c[4] : x * c[1];
}

lli r (lli x) {
  return x <= 0 ? -x * c[5] : x * c[2];
}

lli g (lli x) {
  return x <= 0 ? -x * c[3] : x * c[6];
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    lli x, y;
    scanf("%lld %lld", &x, &y);
    FOR(i, 1, 7) {
      scanf("%lld", c + i);
    }
    lli rg = g(x) + r(y);
    lli rb = b(x) + r(y - x);
    lli bg = b(y) + g(x - y);
    printf("%lld\n", min({rg, rb, bg}));
  }
  return 0;
}
