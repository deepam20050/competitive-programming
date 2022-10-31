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

const int N = 3e5 + 5;
const lli inf = 1e18;

vector < pii > g[N];
int weight[N];
lli dist[N];
int pre[N];
priority_queue < pair < lli, int > > pq;

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  FOR(i, 1, m + 1) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    g[a].eb(b, i);
    g[b].eb(a, i);
    weight[i] = w;
  }
  fill(dist, dist + N, inf);
  int source;
  scanf("%d", &source);
  dist[source] = 0;
  pre[source] = 0;
  pq.em(0, source);
  while (!pq.empty()) {
    auto [ignore, u] = pq.top();
    pq.pop();
    for (auto [to, id] : g[u]) {
      int w = weight[id];
      if (dist[to] > dist[u] + w) {
        dist[to] = dist[u] + w;
        pq.em(-dist[to], to);
        pre[to] = id;
      } else if (dist[to] == dist[u] + w && weight[pre[to]] > w) {
        pre[to] = id;
      }
    }
  }
  lli sum = 0;
  FOR(i, 1, n + 1) {
    sum += weight[pre[i]];
  }
  printf("%lld\n", sum);
  FOR(i, 1, n + 1) {
    if (i != source) {
      printf("%d ", pre[i]);
    }
  }
  return 0;
}
