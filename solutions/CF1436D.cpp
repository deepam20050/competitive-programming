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

const int N = 2e5 + 5;

vector < int > g[N];
int leaves[N];
lli a[N];
int n;
lli ans;

void dfs (int u) {
  leaves[u] = g[u].empty();
  for (auto &to : g[u]) {
    dfs(to);
    a[u] += a[to];
    leaves[u] += leaves[to];
  }
  if (a[u]) {
    ans = max(ans, (a[u] + leaves[u] - 1) / leaves[u]);
  }
}

int main () {
  scanf("%d", &n);
  FOR(i, 1, n) {
    int x;
    scanf("%d", &x);
    g[x - 1].eb(i);
  }
  FOR(i, 0, n) {
    scanf("%d", a + i);
  }
  dfs(0);
  printf("%lld\n", ans);
  return 0;
}