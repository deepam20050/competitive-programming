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

int n, k, dep[N];
int pr[N];
vector < int > g[N];

void rekt () {
  puts("No");
  exit(0);
}

void dfs (int u, int parent) {
  for (auto &to : g[u]) {
    if (to != parent) {
      pr[to] = u;
      dep[to] = dep[u] + 1;
      dfs(to, u);
    }
  }
}

void check (int u, int parent) {
  if (dep[u] < k && sz(g[u]) + !parent < 4) {
    rekt();
  }
  if (dep[u] >= k && sz(g[u]) != 1) {
    rekt();
  }
  for (auto &to : g[u]) {
    if (to != parent) {
      check(to, u);
    }
  }
}

int main () {
  scanf("%d %d", &n, &k);
  FOR(i, 1, n) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].eb(b);
    g[b].eb(a);
  }
  dfs(1, 0);
  int root = max_element(dep + 1, dep + n + 1) - dep;
  dep[root] = 0;
  dfs(root, 0);
  root = max_element(dep, dep + n + 1) - dep;
  int len = dep[root];
  if (len != 2 * k) {
    rekt();
  }
  FOR(i, 0, len >> 1) {
    root = pr[root];
  }
  dep[root] = 0;
  dfs(root, 0);
  check(root, 0);
  puts("Yes");
  return 0;
}
