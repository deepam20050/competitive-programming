// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 2005;

vector < int > g[N];
int c[N];
int ans[N];
int sz[N];
int root;

vector < int > dfs (int u) {
  sz[u] = 1;
  vector < int > ret;
  for (auto &to : g[u]) {
    auto p = dfs(to);
    for (auto &x : p) ret.eb(x);
    sz[u] += sz[to];
  }
  if (c[u] > sz[u] - 1) {
    puts("NO");
    exit(0);
  }
  ret.insert(ret.begin() + c[u], u);
  return ret;
}

int main () {
  int n;
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    int p;
    scanf("%d %d", &p, c + i);
    if (p) {
      g[p].eb(i);
    } else {
      root = i;
    }
  }
  auto v = dfs(root);
  FOR(i, 0, n) {
    ans[v[i]] = i;
  }
  puts("YES");
  FOR(i, 1, n + 1) {
    printf("%d ", ans[i] + 1);
  }
  return 0;
}
