#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "../algo/debug.hpp"
#else
#define debug(...) 0
#endif

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

lli s (lli x) {
  lli t = 0;
  while (x > 0) {
    t += x % 10;
    x /= 10;
  }
  return t;
}

int main () {
  #ifdef DEBUG
  freopen("debug.txt", "w", stderr);
  #endif
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout << fixed << setprecision(15); cerr << fixed << setprecision(10);
  lli n; cin >> n;
  FOR(k, 1, 163) {
    lli delta = k * 1ll * k + 4 * n;
    lli sqrt_delta = sqrt(delta);
    if (sqrt_delta * sqrt_delta != delta) continue;
    if (-k + sqrt_delta > 0 && !((-k + sqrt_delta) & 1)) {
      lli x = (-k + sqrt_delta) >> 1ll;
      if (s(x) == k) {
        cout << x << '\n';
        exit(0);
      }
    }
  }
  cout << -1;
  return 0;
}