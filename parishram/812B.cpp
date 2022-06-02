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

const int inf = 1e9;
const int N = 20;
const int M = 105;

bool lit[N][M];
int dp[N][2];
char s[M];

int main () {
  int n, m; scanf("%d %d", &n, &m);
  m += 2;
  for (int i = n - 1; i >= 0; --i) {
    scanf("%s", s);
    FOR(j, 0, m) {
      lit[i][j] = s[j] == '1';
    }
  }
  FOR(i, 0, N) dp[i][0] = dp[i][1] = inf;
  int ans = 0;
  dp[0][0] = 0;
  FOR(i, 0, n) {
    int hi = 0, lo = m - 1;
    FOR(j, 0, m) {
      if (lit[i][j]) {
        ckmax(hi, j);
        ckmin(lo, j);
      }
    }
    ckmin(dp[i + 1][0], dp[i][0] + 2 * hi + 1);
    ckmin(dp[i + 1][0], dp[i][1] + m);
    ckmin(dp[i + 1][1], dp[i][1] + 2 * (m - 1 - lo) + 1);
    ckmin(dp[i + 1][1], dp[i][0] + m);
    if (hi != 0) {
      ans = min(dp[i][0] + hi, dp[i][1] + m - 1 - lo);
    } 
  }
  printf("%d\n", ans);
  return 0;
}