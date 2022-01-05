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

vector < int > g[N];
bitset < N > visited;
int n, m;
set < int > present;
queue < int > q, tonode;

void solve (int node) {
  visited[node] = 1;
  if (present.find(node) != present.end()) {
    present.erase(node);
  }
  for (auto &to : present) {
    if (to == node || visited[to]) continue;
    if (!binary_search(all(g[node]), to)) {
      tonode.em(to);
    }
  }
  while (!tonode.empty()) {
    int x = tonode.front();
    present.erase(x);
    q.em(x);
    tonode.pop();
  }
}

void bfs (int node) {
  while (!q.empty()) q.pop();
  q.em(node);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    solve(u);
  }
}

int main () {
  scanf("%d %d", &n, &m);
  FOR(i, 0, m) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    g[x].eb(y);
    g[y].eb(x);
  }
  FOR(i, 0, n) {
    sort(all(g[i]));
    present.em(i);
  }
  int nodes = 0;
  FOR(i, 0, n) {
    if (visited[i]) continue;
    if (present.empty()) break;
    ++nodes;
    bfs(i);
  }
  printf("%d\n", nodes - 1);
  return 0;
}
