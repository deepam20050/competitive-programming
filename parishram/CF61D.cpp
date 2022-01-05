// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 1e5 + 5;

vector < pii > g[N];
int subtree[N];
lli ans = 9e18;
int n;

int dfs1 (int u, int pr = -1) {
  for (auto &[to, w] : g[u]) {
    if (to != pr) {
      subtree[u] += w + dfs1(to, u);
    }
  }
  return subtree[u];
}

void dfs2 (int u, int pr = -1, lli plus = 0) {
  bool leaf = 1;
  for (auto &[to, w] : g[u]) {
    if (to != pr) {
      leaf = 0;
      lli add = w + (subtree[u] - (w + subtree[to])) * 2ll + plus;
      dfs2(to, u, add);
    }
  }
  if (leaf) {
    ans = min(ans, plus);
  }
}

int main () {
  scanf("%d", &n);
  FOR(i, 1, n) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    g[a].eb(b, c);
    g[b].eb(a, c);
  }
  dfs1(1);
  dfs2(1);
  printf("%lld\n", ans);
  return 0;
}
