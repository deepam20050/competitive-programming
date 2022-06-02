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
lli s[N];
lli a[N];

void dfs (int u, lli sum, int h) {
  if (h & 1) {
    a[u] = s[u] - sum;
  } else {
    if (!g[u].empty()) {
      a[u] = (int)1e9 + 5;
    }
    for (auto &to : g[u]) {
      if (s[to] < sum) {
        cout << -1 << '\n';
        exit(0);
      } else {
        a[u] = min(a[u], s[to] - sum);
      }
    }
  }
  for (auto &to : g[u]) {
    dfs(to, sum + a[u], h + 1);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  FOR(i, 2, n + 1) {
    int p; cin >> p;
    g[p].eb(i);
  }
  FOR(i, 1, n + 1) {
    cin >> s[i];
  }
  dfs(1, 0, 1);
  printf("%lld\n", accumulate(a + 1, a + n + 1, 0ll));
  return 0;
}