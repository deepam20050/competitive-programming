// AC
#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 5;

vector < int > g[N];
int cool[N];
long long subtree[N], dp[N];
long long kewl_ans;

long long dfs (int u, int pr = -1) {
  subtree[u] = 1LL * cool[u];
  dp[u] = -(1LL << 60);
  vector < long long > vec;
  for (int &v : g[u]) {
    if (v != pr) {
      subtree[u] += dfs(v, u);
      dp[u] = max(dp[u], dp[v]);
      vec.emplace_back(dp[v]);
    }
  }
  dp[u] = max(dp[u], subtree[u]);
  sort(vec.begin(), vec.end(), greater < long long > ());
  if (vec.size() >= 2) {
    kewl_ans = max(kewl_ans, 1LL * vec[0] + 1LL * vec[1]);
  }
  return subtree[u];
}

int main () {
  kewl_ans = -(1LL << 60);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", cool + i);
  }
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  dfs(1);
  kewl_ans == -(1LL << 60) ? puts("Impossible") : printf("%lld", kewl_ans);
  return 0;
}
