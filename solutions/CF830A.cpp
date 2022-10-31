// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 1005;
const int K = 2005;

int a[N], b[K];
int n, k, p;

lli solve (int l, int r) {
  lli res = 0;
  FOR(i, l, r + 1) {
    lli tmp = abs(b[i] - a[i - l + 1]);
    tmp += abs(p - b[i]);
    res = max(res, tmp);
  }
  return res;
}

int main () {
  scanf("%d %d %d", &n, &k, &p);
  FOR(i, 1, n + 1) scanf("%d", a + i);
  FOR(i, 1, k + 1) scanf("%d", b + i);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + k + 1);
  lli ans = 1e18;
  for (int i = 1; i + n - 1 <= k; ++i) {
    ans = min(ans, solve(i, i + n - 1));
  }
  printf("%lld\n", ans);
  return 0;
}
