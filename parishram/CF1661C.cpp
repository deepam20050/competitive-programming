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

int h[N];
int mx;
int n;

bool f (lli x) {
  lli even = x >> 1ll;
  lli odd = even + (x & 1ll);
  FOR(i, 1, n + 1) {
    if (h[i] == mx) {
      continue;
    }
    int req = mx - h[i];
    lli r_even = req >> 1;
    lli r_odd = req & 1;
    odd -= r_odd * 1ll;
    if (r_even <= even) {
      even -= r_even * 1ll;
    } else {
      lli mini = min({r_even, even});
      even -= mini;
      r_even -= mini;
      odd -= r_even * 2ll;
    }
  }
  return even >= 0 && odd >= 0;
}

void solve () {
  scanf("%d", &n);
  mx = 0;
  FOR(i, 1, n + 1) {
    scanf("%d", h + i);
    mx = max(mx, h[i]);
  }
  lli l = 0, r = 1e18;
  FOR(i, 0, 63) {
    lli mid = l + r >> 1ll;
    if (f(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  ++mx;
  lli ans = r;
  l = 0;
  r = 1e18;
  FOR(i, 0, 63) {
    lli mid = l + r >> 1ll;
    if (f(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%lld\n", min(ans, r));
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
