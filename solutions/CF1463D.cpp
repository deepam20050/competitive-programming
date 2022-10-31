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
  int n;
  scanf("%d", &n);
  vector < int > a(n), b(n);
  set < int > s;
  FOR(i, 1, 2 * n + 1) {
    s.em(i);
  }
  for (auto &e : a) {
    scanf("%d", &e);
    s.erase(e);
  }
  auto f = [&] (int x) {
    auto it = s.rbegin();
    for (int i = x - 1; i >= 0; --i, ++it) {
      b[i] = *it;
    }
    FOR(i, x, n) {
      b[i] = *it;
      ++it;
    }
    bool ok = 1;
    FOR(i, 0, n) {
      if (i < x) {
        ok &= min(a[i], b[i]) == a[i];
      } else {
        ok &= max(a[i], b[i]) == a[i];
      }
    }
    return ok;
  };
  int l = 0, r = n;
  FOR(i, 0, 20) {
    int mid = l + r >> 1;
    if (f(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  printf("%d\n", l);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
