const int N = 3002;
 
string s, t;
int dp[N][N];
 
void test_case() {
cin >> s >> t;
int n = sz(s), m = sz(t);
for (int i = 1; i <= n; ++i) {
  for (int j = 1; j <= m; ++j) {
    if (s[i - 1] == t[j - 1]) {
      dp[i][j] = dp[i - 1][j - 1] + 1;
    } else {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
}
string ans;
int i = n, j = m;
while (i > 0 && j > 0) {
  if (s[i - 1] == t[j - 1]) {
    ans += s[i - 1];
    --i;
    --j;
  } else if (dp[i - 1][j] > dp[i][j - 1]) {
    --i;
  } else {
    --j;
  }
}