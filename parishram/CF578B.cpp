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

lli a[N];
lli p[N], s[N];

int main () {
  int n, k, x;
  scanf("%d %d %d", &n, &k, &x);
  FOR(i, 1, n + 1) {
    scanf("%lld", a + i);
    p[i] = p[i - 1] | a[i];
  }
  for (int i = n; i >= 1; --i) {
    s[i] = s[i + 1] | a[i];
  }
  lli pw = 1;
  while (k--) {
    pw *= x;
  }
  lli ans = 0;
  FOR(i, 1, n + 1) {
    ans = max(ans, p[i - 1] | (a[i] * pw) | s[i + 1]);
  }
  printf("%lld\n", ans);
  return 0;
}
