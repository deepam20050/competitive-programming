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

int used[N];
vector < int > g[N], topo;
bool cycle;
int pos[N];
vector < pii > e;
int n, m;

void dfs (int u) {
  used[u] = 1;
  for (auto &to : g[u]) {
    if (!used[to]) {
      dfs(to);
    } else if (used[to] == 1) {
      cycle = 1;
    }
  }
  used[u] = 2;
  topo.eb(u);
}

void solve () {
  scanf("%d %d", &n, &m);
  e.clear();
  topo.clear();
  cycle = 0;
  FOR(i, 1, n + 1) {
    g[i].clear();
    used[i] = 0;
  }
  FOR(i, 0, m) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == 0) {
      e.eb(b, c);
    } else {
      g[b].eb(c);
    }
  }
  FOR(i, 1, n + 1) {
    if (!used[i]) dfs(i);
  }
  if (cycle) {
    puts("NO");
    return;
  }
  reverse(all(topo));
  FOR(i, 0, sz(topo)) {
    pos[topo[i]] = i;
  }
  for (auto [u, v] : e) {
    if (pos[u] < pos[v]) {
      g[u].eb(v);
    } else {
      g[v].eb(u);
    }
  }
  puts("YES");
  FOR(i, 1, n + 1) {
    for (auto &to : g[i]) {
      printf("%d %d\n", i, to);
    }
  }
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
