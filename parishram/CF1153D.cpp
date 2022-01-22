#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 3e5 + 5;

int dp[N];
int n;
vector < int > g[N];
int leaf;
int op[N];
bool ok;

void dfs (int u) {
  if (g[u].empty()) {
    dp[u] = 1;
    return;
  }
  if (op[u]) {
    dp[u] = leaf;
  }
  for (auto &to : g[u]) {
    dfs(to);
    if (op[u] == 0) {
      dp[u] += dp[to];
    } else {
      dp[u] = min(dp[u], dp[to]);
    }
  }
}

int main () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", op + i);
  }
  FOR(i, 2, n + 1) {
    int p;
    scanf("%d", &p);
    g[p].eb(i);
  }
  FOR(i, 1, n + 1) {
    leaf += g[i].empty();
  }
  dfs(1);
  printf("%d\n", leaf + 1 - dp[1]);
  return 0;
}
