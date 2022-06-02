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

const int N = 2e5 + 5;

vector < int > order;
int tin[N], tout[N], timer;
vector < int > g[N];
int first[N];

void dfs (int u) {
  order.eb(u);
  tin[u] = ++timer;
  for (auto &to : g[u]) {
    dfs(to);
  }
  tout[u] = ++timer;
}

int main () {
  int n, nq; scanf("%d %d", &n, &nq);
  FOR(i, 2, n + 1) {
    int p; scanf("%d", &p);
    g[p].eb(i);
  }
  dfs(1);
  memset(first, -1, sizeof first);
  FOR(i, 0, n) {
    int x = order[i];
    if (first[x] == -1) {
      first[x] = i;
    }
  }
  while (nq--) {
    int u, k; scanf("%d %d", &u, &k);
    int idx1 = first[u];
    --k;
    if (idx1 + k >= n) {
      puts("-1");
      continue;
    }
    int who = order[idx1 + k];
    if (tin[u] <= tin[who] && tout[who] <= tout[u]) {
      printf("%d\n", who);
    } else {
      puts("-1");
    }
  }
  return 0;
}