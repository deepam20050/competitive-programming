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

lli m;

lli f (lli n) {
  lli cnt = 0;
  for (lli k = 2; k * k * k <= n; ++k) {
    cnt += n / (k * k * k);
  }
  return cnt;
}

int main () {
  scanf("%lld", &m);
  lli l = 1, r = 1e18;
  FOR(i, 0, 65) {
    lli midx = l + r >> 1ll;
    if (f(midx) >= m) {
      r = midx;
    } else {
      l = midx;
    }
  }
  if (f(r) != m) {
    puts("-1");
    exit(0);
  }
  printf("%lld\n", r);
  return 0;
}