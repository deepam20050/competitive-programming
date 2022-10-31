#include "bits/stdc++.h"

using namespace std;

const int N = 1005;

int dp[N][2];
char s[N][N];
int white[N];
int black[N];

int main () {
  int n, m, x, y;
  scanf("%d %d %d %d", &n, &m, &x, &y);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }  
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      black[i] += s[j][i] == '#';
      white[i] += s[j][i] == '.';
    }
  }
  for (int j = m - 1; j >= 0; --j) {
    dp[j][0] = 1e6;
    dp[j][1] = 1e6;
    int k = j;
    int w = 0, b = 0;
    while (k < m && k - j + 1 <= x) {
      w += white[k];
      b += black[k];
      ++k;
    }
    if (k - j == x) {
      dp[j][0] = b + dp[k][1];
      dp[j][1] = w + dp[k][0];
    }
    while (k < m && k - j + 1 <= y) {
      w += white[k];
      b += black[k];
      dp[j][0] = min(dp[j][0], b + dp[k + 1][1]);
      dp[j][1] = min(dp[j][1], w + dp[k + 1][0]);
      ++k;
    }
  }
  printf("%d\n", min(dp[0][0], dp[0][1]));
  return 0;
}
