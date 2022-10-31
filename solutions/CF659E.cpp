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

const int N = 1e5 + 5;

vector < int > g[N];
bool used[N];
int cycle;

void dfs (int u, int pr) {
  used[u] = 1;
  for (auto &to : g[u]) {
    if (to == pr) {
      continue;
    }
    if (!used[to]) {
      dfs(to, u);
    } else {
      cycle = 1;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  FOR(i, 0, m) {
    int a, b; cin >> a >> b;
    g[a].eb(b);
    g[b].eb(a);
  }
  int ans = 0;
  FOR(i, 1, n + 1) {
    if (!used[i]) {
      cycle = 0;
      dfs(i, i);
      ans += !cycle;
    }
  }
  cout << ans;
  return 0;
}
