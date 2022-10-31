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

bitset < N > mark, used;
vector < int > topo, ans_v;
int b[N];
lli a[N];
lli ans;
int n;

void dfs1 (int u) {
  used[u] = 1;
  if (b[u] != -1 && !used[b[u]]) {
    dfs1(b[u]);
  }
  topo.eb(u);
}

int main () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%lld", a + i);
  }
  FOR(i, 1, n + 1) {
    scanf("%d", b + i);
  }
  FOR(i, 1, n + 1) {
    if (!used[i]) {
      dfs1(i);
    }
  }
  reverse(all(topo));
  for (auto &u : topo) {
    if (a[u] > 0 && !mark[u]) {
      mark[u] = 1;
      ans += a[u];
      ans_v.eb(u);
      if (b[u] != -1) {
        a[b[u]] += a[u];
      }
    }
  }
  for (int i = sz(topo) - 1; i >= 0; --i) {
    int u = topo[i];
    if (!mark[u]) {
      mark[u] = 1;
      ans += a[u];
      ans_v.eb(u);
    }
  }
  printf("%lld\n", ans);
  for (auto &e : ans_v) {
    printf("%d ", e);
  }
  return 0;
}
