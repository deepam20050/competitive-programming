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

const int N = 3e5 + 5;

vector < int > g[N];
int n, x, y;
int cnt[N];
int pr[N];

int dfs (int u, int p) {
  for (auto &to : g[u]) {
    if (to != p) {
      pr[to] = u;
      cnt[u] += dfs(to, u);
    }
  }
  ++cnt[u];
  return cnt[u];
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> x >> y;
  FOR(i, 1, n) {
    int a, b; cin >> a >> b;
    g[a].eb(b);
    g[b].eb(a);
  } 
  dfs(x, -1);
  int c1 = cnt[y];
  int p = y;
  while (p != x) {
    if (pr[p] == x) {
      cnt[x] -= cnt[p];
    }
    p = pr[p];
  }
  lli del = c1 * 1ll * cnt[x];
  lli tot = n * 1ll * (n - 1);
  cout << tot - del << '\n';
  return 0;
}