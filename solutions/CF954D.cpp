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

const int N = 1005;

vector < int > g[N];
bool used[N];
bool mat[N][N];
int dist[2][N];

void bfs (int startx, int who) {
  memset(used, 0, sizeof used);
  queue < int > q;
  q.em(startx);
  used[startx] = 1;
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (auto &to : g[u]) {
      if (!used[to]) {
        used[to] = 1;
        dist[who][to] = dist[who][u] + 1;
        q.em(to);
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, s, t;  cin >> n >> m >> s >> t;
  FOR(i, 0, m) {
    int a, b; cin >> a >> b;
    g[a].eb(b);
    g[b].eb(a);
    mat[a][b] = mat[b][a] = 1;
  }
  bfs(s, 0);
  bfs(t, 1);
  int ans = 0;
  FOR(i, 1, n + 1) FOR(j, i + 1, n + 1) {
    if (mat[i][j]) continue;
    int x = i, y = j;
    if (dist[0][x] > dist[0][y]) {
      swap(x, y);
    }
    int best = 1 + dist[0][x] + dist[1][y];
    if (best >= dist[0][t]) {
      ++ans;
    }
  }
  cout << ans;
  return 0;
}
