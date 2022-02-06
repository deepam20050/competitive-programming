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

const int N = 1e5 + 5;
const int M = 105;

int n, k;
int a[M];
int dp[M][N];

int main () {
  scanf("%d %d", &n, &k);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
  }
  memset(dp, -3, sizeof dp);
  dp[0][10000] = 0;
  FOR(i, 1, n + 1) {
    int b;
    scanf("%d", &b);
    b = a[i] - k * b;
    FOR(j, 0, 20001) {
      dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - b] + a[i]);
    }
  }
  dp[n][10000] == 0 ? puts("-1") : printf("%d\n", dp[n][10000]);
  return 0;
}
