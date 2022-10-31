#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
  #include "../algo/debug.hpp"
#else
  #define debug(...)
#endif
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back

using lli = long long;
using pii = pair < int, int >;
template < class T >
using min_heap = priority_queue < T, vector < T >, greater < T > >; 

const int N = 2e5 + 5;
const lli inf = 1e18;

vector < array < int, 3 > > g[N];
lli dist[N];
min_heap < pair < lli, int > > pq;
int p[N];
bool used[N];
int n, m;
bool vis[N];

void test_case() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b, c; cin >> a >> b >> c;
    g[a].emplace_back(array{b, c, i + 1});
    g[b].emplace_back(array{a, c, i + 1});
  }
  fill(dist + 1, dist + n + 1, inf);
  dist[1] = 0;
  pq.emplace(0, 1);
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    used[p[u]] = 1;
    for (auto [to, w, i] : g[u]) {
      if (dist[to] > d + w) {
        dist[to] = d + w;
        p[to] = i;
        pq.emplace(dist[to], to);
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (used[i]) {
      cout << i << " ";
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}