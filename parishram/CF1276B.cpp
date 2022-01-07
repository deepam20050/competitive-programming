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

int n, m;
int fair[2];
bool used[N];
bool visited[N][2];
vector < int > g[N];

void dfs (int u, int idx) {
  used[u] = 1;
  visited[u][idx] = 1;
  for (auto to : g[u]) {
    if (used[to] || to == fair[idx ^ 1]) continue;
    dfs(to, idx);
  }
}

void solve () {
  cin >> n >> m >> fair[0] >> fair[1];
  FOR(i, 1, n + 1) g[i].clear();
  memset(visited, 0, sizeof (visited));
  FOR(i, 0, m) {
    int x, y;
    cin >> x >> y;
    g[x].eb(y);
    g[y].eb(x);
  }
  memset(used, 0, sizeof used);
  dfs(fair[0], 0);
  memset(used, 0, sizeof used);
  dfs(fair[1], 1);
  int freq[] = {0, 0};
  FOR(i, 1, n + 1) {
    if (i == fair[0] || i == fair[1]) continue;
    if (visited[i][0] && !visited[i][1]) ++freq[0];
    if (!visited[i][0] && visited[i][1]) ++freq[1];
  }
  printf("%lld\n", (freq[0]) * 1ll * (freq[1]));
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
