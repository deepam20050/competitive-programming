// A
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 2005;

int dp[N][N][2];
int n;
int arr[N];
int pref[N][2];

int main () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", arr + i);
    --arr[i];
    int x = arr[i];
    pref[i][x] = 1 + pref[i - 1][x];
    pref[i][x ^ 1] = pref[i - 1][x ^ 1];
    dp[i][i][x] = 1;
    dp[i][i][x ^ 1] = 0;
  }
  FOR(i, 1, n + 1) {
    for (int j = 1; j + i - 1 <= n; ++j) {
      int r = j + i - 1;
      int l = i;
      int x = arr[r];
      if (x == 0) {
        dp[l][r][x] = 1 + max(dp[l][r - 1][x], dp[l][r - 1][x ^ 1]);
      } else {
        dp[l][r][x] = 1 + dp[l][r - 1][x];
      }
      dp[l][r][x ^ 1] = dp[l][r - 1][x ^ 1];
    }
  }
  int ans = max(pref[n][0], pref[n][1]);
  FOR(i, 1, n + 1) {
    FOR(j, i, n + 1) {
      int l = i, r = j;
      int L = pref[l - 1][0];
      int R = pref[n][1] - pref[r][1];
      ans = max(ans, L + R + max({dp[l][r][1], dp[l][r][0]}));
    }
  }
  printf("%d\n", ans);
  return 0;
}
