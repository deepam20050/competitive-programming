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
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

const int N = 3005;

vector < int > g[N];
queue < int > q;
int used[N];
int p[N];
int d[N];
bool vis[N];

void dfs (int u, int pr) {
  p[u] = pr;
  used[u] = 1;
  for (auto &to : g[u]) {
    if (to == pr) continue;
    if (!used[to]) {
      dfs(to, u);
    } else if (used[to] == 1) {
      int x = u;
      vis[to] = 1;
      q.em(to);
      while (x != to) {
        q.em(x);
        vis[x] = 1;
        x = p[x];
      }
    }
  }
  used[u] = 2;
}

int main () {
  int n; scanf("%d", &n);
  FOR(i, 0, n) {
    int x, y; scanf("%d %d", &x, &y);
    g[x].eb(y);
    g[y].eb(x);
  }
  dfs(1, 0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &to : g[u]) {
      if (!vis[to]) {
        d[to] = d[u] + 1;
        q.em(to);
        vis[to] = 1;
      }
    }
  }
  FOR(i, 1, n + 1) {
    printf("%d ", d[i]);
  }
  return 0;
}