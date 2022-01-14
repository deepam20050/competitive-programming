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

const int N = 2e5 + 5;

lli h[N];
lli arr[N];
int n;

bool f (lli target) {
  FOR(i, 1, n + 1) arr[i] = h[i];
  for (int i = n; i >= 3; --i) {
    if (arr[i] < target) return 0;
    auto d = (arr[i] - target) / 3;
    arr[i - 2] += 2 * d;
    arr[i - 1] += d;
    arr[i] -= 3 * d;
  }
  FOR(i, 1, n + 1) if (arr[i] < target) return 0;
  return 1;
}

void solve () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%lld", h + i);
  }
  lli l = 0, r = h[n];
  FOR(i, 0, 35) {
    lli m = l + r >> 1ll;
    if (f(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  printf("%lld\n", l);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
