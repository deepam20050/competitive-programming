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
int used[N];
int n;
vector < int > cycle;
int p[N];
bitset < N > good;

lli calc (int x) {
  return x * 1ll * (x - 1) >> 1ll;
}

void dfs (int u, int pr) {
  used[u] = 1;
  p[u] = pr;
  for (auto &to : g[u]) {
    if (!used[to]) {
      dfs(to, u);
    } else if (used[to] == 1 && to != pr) {
      int x = u;
      while (x != to) {
        cycle.eb(x);
        x = p[x];
      }
      cycle.eb(to);
    }
  }
  used[u] = 2;
}

int dfs2 (int u) {
  used[u] = 1;
  int ret = 1;
  for (auto to : g[u]) {
    if (!used[to] && good[to]) {
      ret += dfs2(to);
    }
  }
  return ret;
}

void solve () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    g[i].clear();
    used[i] = 0;
  }
  FOR(i, 0, n) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].eb(b);
    g[b].eb(a);
  }
  lli ans = 2ll * calc(n);
  cycle.clear();
  dfs(1, 1);
  FOR(i, 1, n + 1) {
    used[i] = 0;
    good[i] = 1;
  }
  for (auto &u : cycle) {
    good[u] = 0;
  }
  for (auto &u : cycle) {
    int x = dfs2(u);
    ans -= calc(x);
  }
  printf("%lld\n", ans);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
