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

int main () {
  int n; scanf("%d", &n);
  queue < int > q;
  vector < int > deg(n), xorsum(n);
  FOR(i, 0, n) {
    scanf("%d %d", &deg[i], &xorsum[i]);
    if (deg[i] == 1) {
      q.em(i);
    }
  }
  vector < pii > ans;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int to = xorsum[u];
    if (deg[u] == 0) {
      continue;
    }
    ans.eb(u, to);
    --deg[to];
    xorsum[to] ^= u;
    if (deg[to] == 1) {
      q.em(to);
    }
  }
  printf("%d\n", sz(ans));
  for (auto [x, y] : ans) {
    printf("%d %d\n", x, y);
  }
  return 0;
}