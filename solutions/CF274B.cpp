#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 5;

vector < int > g[N];
long long val[N];
long long dp1[N], dp2[N];

void dfs (int x, int pr = -1) {
  for (int &to : g[x]) {
    if (to != pr) {
      dfs(to, x);
      dp1[x] = max(dp1[x], dp1[to]);
      dp2[x] = max(dp2[x], dp2[to]);
    }
  }
  if (val[x] + dp1[x] - dp2[x] < 0) {
    dp1[x] = -val[x] + dp2[x];
  } else {
    dp2[x] = val[x] + dp1[x];
  }
}

int main () {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", val + i);
  }
  dfs(1);
  printf("%lld\n", dp1[1] + dp2[1]);
  return 0;
}
