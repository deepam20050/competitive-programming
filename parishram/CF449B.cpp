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
const lli inf = 1e18;

using t3 = tuple < lli, bool, int >;

lli dist[N];
vector < tuple < int, int, int > > g[N];
priority_queue < t3, vector < t3 >, greater < t3 > > pq;
bitset < N > vis;
int del;
int n, m, k;

void dijk () {
  fill(dist, dist + n + 1, inf);
  pq.em(0, 0, 1);
  while (!pq.empty()) {
    auto [d, train, u] = pq.top();
    pq.pop();
    if (vis[u]) continue;
    del += train;
    vis[u] = 1;
    for (auto [yes_train, to, w] : g[u]) {
      if (dist[to] >= w + d) {
        dist[to] = w + d;
        pq.em(dist[to], yes_train, to);
      }
    }
  }
}

int main () {
  scanf("%d %d %d", &n, &m, &k);
  FOR(i, 0, m) {
    int u, v, x;
    scanf("%d %d %d", &u, &v, &x);
    g[u].eb(0, v, x);
    g[v].eb(0, u, x);
  }
  FOR(i, 0, k) {
    int to, y;
    scanf("%d %d", &to, &y);
    g[1].eb(1, to, y);
    g[to].eb(1, 1, y);
  }
  dijk();
  printf("%d\n", k - del);
  return 0;
}
