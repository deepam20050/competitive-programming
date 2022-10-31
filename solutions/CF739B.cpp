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

vector < pii > g[N];
lli dist[N];
int sum[N];
int n;
int p[N];
int a[N];
set < pair < lli, int > > vals;

void dfs1 (int u) {
  for (auto [to, w] : g[u]) {
    dist[to] = dist[u] + w;
    dfs1(to);
  }
}

void dfs2 (int u) {
  auto it = vals.lower_bound(mp(dist[u] - a[u] * 1ll, 0));
  if (it != vals.end()) {
    --sum[p[it->S]];
    ++sum[p[u]];
  }
  for (auto [to, w] : g[u]) {
    vals.em(mp(dist[to], to));
    dfs2(to);
    vals.erase(mp(dist[to], to));
  }
}

int dfs3 (int u) {
  for (auto [to, w] : g[u]) {
    sum[u] += dfs3(to);
  }
  return sum[u];
}

int main () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
  }
  FOR(i, 2, n + 1) {
    int w;
    scanf("%d %d", &p[i], &w);
    g[p[i]].eb(i, w);
  }
  dfs1(1);
  vals.em(mp(0, 0));
  dfs2(1);
  dfs3(1);
  FOR(i, 1, n + 1) {
    printf("%d ", sum[i]);
  }
  return 0;
}
