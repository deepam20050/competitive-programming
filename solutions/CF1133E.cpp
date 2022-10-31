// AC
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

const int N = 5005;

int arr[N];
int cnt[N];
int dp[N][N];

int main () {
  int n, k;
  scanf("%d %d", &n, &k);
  FOR(i, 0, n) {
    scanf("%d", arr + i);
  }
  sort(arr, arr + n);
  FOR(i, 0, n) {
    while (i + cnt[i] < n && arr[i + cnt[i]] - arr[i] <= 5) {
      ++cnt[i];
    }
  }
  FOR(i, 0, n) {
    FOR(j, 0, k + 1) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j + 1 <= k) {
        dp[i + cnt[i]][j + 1] = max(dp[i + cnt[i]][j + 1], dp[i][j] + cnt[i]);
      }
    }
  }
  printf("%d\n", dp[n][k]);
  return 0;
}
