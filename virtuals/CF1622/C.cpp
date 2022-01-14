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

int a[N];
lli p[N];
int n;
lli k;

bool f (lli chance) {
  if (p[n] - chance <= k) return 1;
  for (int i = n, len = 1; i >= 1 && len <= chance; --i, ++len) {
    lli x = a[1] - (chance - len);
    lli t = p[i - 1] - (i > 1 ? a[1] : 0) + x + len * x;
    if (t <= k) return 1;
  }
  return 0;
}

void solve () {
  scanf("%d %lld", &n, &k);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + n + 1);
  FOR(i, 1, n + 1) {
    p[i] = p[i - 1] + a[i];
  }
  if (p[n] <= k) {
    puts("0");
    return;
  }
  lli l = 1, r = 1e16;
  FOR(i, 0, 60) {
    auto m = l + r >> 1ll;
    if (f(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  printf("%lld\n", r);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
