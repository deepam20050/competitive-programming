#include "bits/stdc++.h"

using namespace std;

const int N = 105;

int dp[N][N][20], a[N][N][20];
int n;
int q;
int c;

int get (int x1, int y1, int x2, int y2, int k) {
  return dp[x2][y2][k] - dp[x1 - 1][y2][k] - dp[x2][y1 - 1][k] + dp[x1 - 1][y1 - 1][k];
}

int main () {
  scanf("%d %d %d", &n, &q, &c);
  for (int i = 0; i < n; ++i) {
    int x, y, s;
    scanf("%d %d %d", &x, &y, &s);
    ++a[x][y][s];
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < N; ++j) {
      for (int k = 0; k <= c; ++k) {
        dp[i][j][k] = a[i][j][k] + dp[i][j - 1][k] + dp[i - 1][j][k] - dp[i - 1][j - 1][k];
      }
    }
  }
  while (q--) {
    int ti, x1, y1, x2, y2;
    scanf("%d %d %d %d %d", &ti, &x1, &y1, &x2, &y2);
    int ans = 0;
    for (int i = 0; i <= c; ++i) {
      ans += get(x1, y1, x2, y2, i) * ((i + ti) % (c + 1)); 
    }
    printf("%d\n", ans);
  }
  return 0;
}
