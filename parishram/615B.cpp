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

template < class T > bool ckmin (T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template < class T > bool ckmax (T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1e5 + 5;

int dp[N];
vector < int > g[N];

int main () {
  int n, m; scanf("%d %d", &n, &m);
  FOR(i, 0, m) {
    int x, y; scanf("%d %d", &x, &y);
    g[x].eb(y);
    g[y].eb(x);
  }
  lli ans = 0;
  FOR(i, 1, n + 1) {
    dp[i] = 1;
    for (auto next : g[i]) {
      if (next < i) {
        ckmax(dp[i], 1 + dp[next]);
      }
    }
    ckmax(ans, dp[i] * 1ll * sz(g[i]));
  }
  printf("%lld\n", ans);
  return 0;
}