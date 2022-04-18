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

const int N = 2e5 + 5;

int p[N];
int x[N], y[N];
int siz[N];
set < pii > st;
vector < int > g[N], gt[N];
bitset < N > used;
vector < pii > ans;

void rekt () {
  puts("NO");
  exit(0);
}

int find (int a) {
  return p[a] == a ? a : p[a] = find(p[a]);
}

void join (int a, int b) {
  a = find(a);
  b = find(b);
  if (siz[a] < siz[b]) {
    swap(a, b);
  }
  siz[a] += siz[b];
  p[b] = a;
}

void bfs (int u) {
  used.reset();
  used[u] = 1;
  queue < int > q;
  q.em(u);
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (auto &to : gt[u]) {
      if (!used[to]) {
        used[to] = 1;
        q.em(to);
        ans.eb(u, to);
      }
    }
  }
}

int main () {
  int n, m, d;
  scanf("%d %d %d", &n, &m, &d);
  FOR(i, 1, n + 1) {
    p[i] = i;
    siz[i] = 1;
  }
  FOR(i, 0, m) {
    scanf("%d %d", x + i, y + i);
    if (!(x[i] == 1 || y[i] == 1)) {
      if (find(x[i]) != find(y[i])) {
        join(x[i], y[i]);
        gt[x[i]].eb(y[i]);
        gt[y[i]].eb(x[i]);
      }
    }
    g[x[i]].eb(y[i]);
    g[y[i]].eb(x[i]);
  }
  if (sz(g[1]) < d) {
    rekt();
  }
  int compos = 0;
  for (auto &e : g[1]) {
    int pr = find(e);
    if (used[pr] == 0) {
      ++compos;
      used[pr] = 1;
    }
  }
  if (compos > d) {
    rekt();
  }
  used.reset();
  int need = d - compos;
  for (auto &e : g[1]) {
    int pr = find(e);
    if (used[pr] && need > 0) {
      --need;
      gt[1].eb(e);
      gt[e].eb(1);
    } else if (!used[pr]) {
      used[pr] = 1;
      gt[1].eb(e);
      gt[e].eb(1);
    }
  }
  bfs(1);
  puts("YES");
  for (auto [lol, fk] : ans) {
    printf("%d %d\n", lol, fk);
  }
  return 0;
}
