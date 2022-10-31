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

const int N = 1e5 + 5;
const int inf = 1e9;

vector < int > g[N];
int down[N], up[N];
bitset < N > marked;
int n, m, d;

void dfs1 (int u, int p) {
  down[u] = marked[u] ? 0 : -inf;
  for (auto &to : g[u]) {
    if (to != p) {
      dfs1(to, u);
      down[u] = max(down[u], down[to] + 1);
    }
  }
}

void dfs2 (int u, int p, int mx) {
  up[u] = mx;
  if (marked[u]) {
    up[u] = max(up[u], 0);
  }
  if (u != p) {
    up[u] = max(up[u], up[p] + 1);
  }
  int mx1 = -inf, mx2 = -inf;
  for (auto &to : g[u]) {
    if (to != p) {
      if (down[to] > mx1) {
        swap(mx2, mx1);
        mx1 = down[to];
      } else if (down[to] > mx2) {
        mx2 = down[to];
      }
    }
  }
  for (auto &to : g[u]) {
    if (to != p) {
      dfs2(to, u, down[to] == mx1 ? mx2 + 2 : mx1 + 2);
    }
  }
}

int main () {
  scanf("%d %d %d", &n, &m, &d);
  FOR(i, 0, m) {
    int x;
    scanf("%d", &x);
    marked[x] = 1;
  }
  FOR(i, 1, n) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].eb(b);
    g[b].eb(a);
  }
  dfs1(1, 1);
  dfs2(1, 1, -inf);
  int ans = 0;
  FOR(u, 1, n + 1) {
    if (up[u] <= d && d >= down[u]) {
      ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
