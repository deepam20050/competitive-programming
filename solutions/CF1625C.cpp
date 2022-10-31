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

const int N = 505;

int x[N], speed[N];
int n, l, k;
int dp[N][N], s[N];

int main () {
  scanf("%d %d %d", &n, &l, &k);
  FOR(i, 1, n + 1) {
    scanf("%d", x + i);
  }
  x[n + 1] = l;
  FOR(i, 1, n + 1) {
    scanf("%d", speed + i);
  }
  FOR(i, 0, N) FOR(j, 0, N) {
    dp[i][j] = 1e9;
  }
  dp[1][0] = 0;
  FOR(i, 2, n + 2) {
    FOR(j, 0, k + 1) {
      FOR(f, 1, i) {
        int d = j - (i - f - 1);
        if (d >= 0) {
          dp[i][j] = min(dp[i][j], dp[f][d] + (x[i] - x[f]) * speed[f]);
        }
      }
    }
  }
  printf("%d\n", *min_element(dp[n + 1], dp[n + 1] + N));
  return 0;
}
