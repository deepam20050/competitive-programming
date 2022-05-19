#include "bits/stdc++.h"

using namespace std;

const int N = 3e4 + 5;
const int M = 502;

int dp[N][M];
int n, m;
int gem[N];
int d;

int f (int pos, int l) {
  if (pos < 1 || pos > m || l < 1) return 0;
  int l_ = l - (d - 250);
  if (dp[pos][l_] != -1) {
    return dp[pos][l_];
  }
  dp[pos][l_] = 0;
  auto &ret = dp[pos][l_];
  for (int add = -1; add <= 1; ++add) {
    ret = max(ret, f(pos + l + add, l + add));
  }
  ret += gem[pos];
  return ret;
}

int main () {
  memset(dp, -1, sizeof dp);
  scanf("%d %d", &n, &d);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    ++gem[x];
    m = max(m, x);
  }
  printf("%d\n", f(d, d));
  return 0;
}
