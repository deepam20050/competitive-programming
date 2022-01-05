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
const int MOD = 1e9 + 7;

vector < lli > edges;
int subtree[N];
vector < int > g[N];
int fac[N];
int n;
int m;

void dfs (int u, int pr = -1) {
  subtree[u] = 1;
  for (auto &to : g[u]) {
    if (to == pr) continue;
    dfs(to, u);
    subtree[u] += subtree[to];
    int x = subtree[to];
    int y = n - x;
    edges.eb(x * 1ll * y);
  }
}

void solve () {
  scanf("%d", &n);
  edges.clear();
  FOR(i, 1, n + 1) { 
    g[i].clear();
    subtree[i] = 0;
  }
  FOR(i, 1, n) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].eb(b);
    g[b].eb(a);
  }
  scanf("%d", &m);
  FOR(i, 0, m) scanf("%d", &fac[i]);
  sort(fac, fac + m, greater < int >());
  dfs(1);
  sort(all(edges), greater < lli > ());
  int j = 0;
  lli ans = 0;
  if (m <= n - 1) {
    FOR(i, 0, n - 1) {
      int req = j >= m ? 1 : fac[j];
      ans += req * 1ll * edges[i] % MOD;
      ans %= MOD;
      ++j;
    }
  } else {
    int diff = m - n + 2;
    int req = 1;
    while (j < diff) {
      req = req * 1ll * fac[j++] % MOD;
    }
    ans += edges[0] * 1ll * req % MOD;
    FOR(i, 1, n - 1) {
      ans += fac[j] * 1ll * edges[i] % MOD;
      ans %= MOD;
      ++j;
    }
  }
  printf("%lld\n", ans);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}