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

lli bit[N];
vector < int > g[N];
vector < pii > queries[N];
lli ans[N];

void update (int idx, int x) {
  while (idx < N) {
    bit[idx] += x;
    idx += idx & -idx;
  }
}

lli query (int idx) {
  lli ret = 0;
  while (idx > 0) {
    ret += bit[idx];
    idx -= idx & -idx;
  }
  return ret;
}

void dfs (int u, int pr, int depth) {
  for (auto [d, x] : queries[u]) {
    update(depth, x);
    update(depth + d + 1, -x);
  }
  ans[u] = query(depth);
  for (auto &to : g[u]) {
    if (to != pr) {
      dfs(to, u, depth + 1);
    }
  }
  for (auto [d, x] : queries[u]) {
    update(depth, -x);
    update(depth + d + 1, x);
  }
}

int main () {
  int n;
  scanf("%d", &n);
  FOR(i, 1, n) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].eb(y);
    g[y].eb(x);
  }
  int nq;
  scanf("%d", &nq);
  while (nq--) {
    int v, d, x;
    scanf("%d %d %d", &v, &d, &x);
    queries[v].eb(d, x);
  }
  dfs(1, 1, 1);
  FOR(i, 1, n + 1) {
    printf("%lld ", ans[i]);
  }
  return 0;
}
