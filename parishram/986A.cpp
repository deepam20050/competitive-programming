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
const int M = 101;

vector < int > what[N], g[N];
bool used[N];
int d[M][N]; 
int n, m, k, s;

void bfs (int type) {
  memset(used, 0, sizeof used);
  queue < int > q;
  for (auto e : what[type]) {
    used[e] = 1;
    d[type][e] = 0;
    q.em(e);
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto to : g[u]) {
      if (!used[to]) {
        d[type][to] = d[type][u] + 1;
        used[to] = 1;
        q.em(to);
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> k >> s;
  FOR(i, 1, n + 1) {
    int x; cin >> x;
    what[x].eb(i);
  }
  FOR(i, 0, m) {
    int x, y; cin >> x >> y;
    g[x].eb(y);
    g[y].eb(x);
  }
  FOR(i, 1, k + 1) {
    bfs(i);
  }
  FOR(i, 1, n + 1) {
    vector < int > v(k);
    FOR(j, 1, k + 1) {
      v[j - 1] = d[j][i];
    }
    sort(all(v));
    cout << accumulate(v.begin(), v.begin() + s, 0ll) << " ";
  }
  return 0;
}