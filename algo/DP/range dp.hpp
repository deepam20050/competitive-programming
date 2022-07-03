// https://atcoder.jp/contests/dp/tasks/dp_n

// dp[l][r] = answer for range [l...r]
// get base cases for dp[l][r] such as dp[l][l], dp[l][r] s.t l > r
// dp[l][r] = make transitons for some k : l <= k < r and then
// dp[l][r] = some operation on (dp[l][k], dp[k + 1][r])

int n; cin >> n;
for (int i = 1; i <= n; ++i) {
  cin >> a[i];
  s[i] = s[i - 1] + a[i];
}
for (int i = n; i >= 1; --i) {
  for (int j = i + 1; j <= n; ++j) {
    dp[i][j] = inf;
    for (int k = i; k < j; ++k) {
      dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
    }
  }
}
cout << dp[1][n] << '\n';