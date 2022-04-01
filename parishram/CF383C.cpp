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

int a[N];
vector < int > g[N];
int tin[N], tout[N], timer;
int depth[N];
int t[N << 1];

void dfs (int u, int pr = -1) {
  tin[u] = ++timer;
  for (auto &to : g[u]) {
    if (to != pr) {
      depth[to] = depth[u] ^ 1;
      dfs(to, u);
    }
  }
  tout[u] = ++timer;
}

void update (int idx, int plus) {
  while (idx <= timer) {
    t[idx] += plus;
    idx += idx & -idx;
  }
}

int query (int idx) {
  int ret = 0;
  while (idx > 0) {
    ret += t[idx];
    idx -= idx & -idx;
  }
  return ret;
}

int main () {
  int n, nq;
  scanf("%d %d", &n, &nq);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
  }
  FOR(i, 1, n) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].eb(b);
    g[b].eb(a);
  }
  dfs(1);
  while (nq--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int x, val;
      scanf("%d %d", &x, &val);
      if (depth[x]) {
        val = -val;
      }
      update(tin[x], val);
      update(tout[x], -val);
    } else {
      int x;
      scanf("%d", &x);
      int ans = query(tin[x]);
      if (depth[x]) {
        ans = -ans;
      }
      printf("%d\n", ans + a[x]);
    }
  }
  return 0;
}
