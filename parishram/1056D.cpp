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
int leaves[N];
int ans[N];

int dfs (int u) {
  leaves[u] = (int)g[u].empty();
  for (auto &to : g[u]) {
    leaves[u] += dfs(to);
  }
  return leaves[u];
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  FOR(i, 2, n + 1) {
    int p; cin >> p;
    g[p].eb(i);
  }
  dfs(1);
  priority_queue < pii, vector < pii >, less < pii > > pq;
  pq.em(leaves[1], 1);
  ans[n + 1] = 2e9;
  for (int i = n; i >= 1; --i) {
    auto [c, u] = pq.top();
    pq.pop();
    ans[i] = min(ans[i + 1], c);
    for (auto to : g[u]) {
      pq.em(leaves[to], to);
    }
  }
  FOR(i, 1, n + 1) {
    cout << ans[i] << " ";
  }
  return 0;
}