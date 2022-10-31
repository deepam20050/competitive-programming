// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 1e5 + 5;

int n, k;
vector < pii > edges;
int d[N];
vector < int > nodes[N];
queue < int > q;
int deg[N];

int main () {
  scanf("%d %d", &n, &k);
  int start = -1;
  FOR(i, 1, n + 1) {
    int x;
    scanf("%d", &x);
    if (x == 0) {
      if (start == -1) start = i;
      else {
        puts("-1");
        return 0;
      }
      continue;
    }
    nodes[x].eb(i);
    d[i] = x;
  }
  if (start == -1) {
    puts("-1");
    return 0;
  }
  q.emplace(start);
  while (!q.empty()) {
    int u = q.front();
    int nxt_d = d[u] + 1;
    while (deg[u] < k && !nodes[nxt_d].empty()) {
      int to = nodes[nxt_d].back();
      edges.eb(u, to);
      q.emplace(to);
      ++deg[to];
      ++deg[u];
      nodes[nxt_d].pop_back();
    }
    q.pop();
  }
  FOR(i, 1, n + 1) {
    if (!deg[i] || !nodes[i].empty()) {
      puts("-1");
      return 0;
    }
  }
  printf("%d\n", sz(edges));
  for (auto &x : edges) {
    printf("%d %d\n", x.F, x.S);
  }
  return 0;
}
