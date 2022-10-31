#include "bits/stdc++.h"

using namespace std;

const int N = 2005;

int dp[N][N], a[N];
int n, h, l, r;

bool f (int x) {
  return l <= x && x <= r;
}

int main () {
  scanf("%d %d %d %d", &n, &h, &l, &r);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < h; ++j) {
      dp[j][i] = max(f((a[i] + j) % h) + dp[(a[i] + j) % h][i + 1], f((a[i] + j - 1 + h) % h) + dp[(a[i] + j - 1 + h) % h][i + 1]);
    }
  }
  printf("%d\n", dp[0][0]);
  return 0;
}
