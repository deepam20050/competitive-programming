#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 5;

int dp[N];

int main () {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    dp[x] = dp[x - 1] + 1;
  }
  printf("%d", n - *max_element(dp + 1, dp + n + 1));
  return 0;
}
