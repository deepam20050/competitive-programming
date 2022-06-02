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
  int n; scanf("%d", &n);
  lli ans = 0;
  vector < int > v(n);
  FOR(i, 0, n) {
    int a, b; scanf("%d %d", &a, &b);
    ans += -a * 1ll + n * 1ll * b;
    v[i] = a - b;
  }
  sort(all(v), greater < int > ());
  FOR(i, 0, n) {
    ans += 1ll * (i + 1) * v[i];
  }
  printf("%lld\n", ans);
  return 0;
}