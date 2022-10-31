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

vector < int > g[N];
int depth[N];
bitset < N > used;
int dad[N];
int n;
int curr = 0;
int lmao = -1;

void dfs1 (int u, int p) {
  for (auto &to : g[u]) {
    if (to != p) {
      depth[to] = depth[u] + 1;
      dfs1(to, u);
    }
  }
}

void dfs2 (int u, int p) {
  for (auto &to : g[u]) {
    if (to != p) {
      dad[to] = u;
      depth[to] = depth[u] + 1;
      dfs2(to, u);
    }
  }
}


void dfs3 (int u, int p, int up) {
  if (up > curr) {
    curr = up;
    lmao = u;
  }
  for (auto &to : g[u]) {
    if (to != p && !used[to]) {
      dfs3(to, u, up + 1);
    }
  }
}

int main () {
  scanf("%d", &n);
  FOR(i, 1, n) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].eb(b);
    g[b].eb(a);
  }
  dfs1(1, 1);
  int l = max_element(depth + 1, depth + n + 1) - depth;
  depth[l] = 0;
  dad[l] = 0;
  dfs2(l, l);
  int r = max_element(depth + 1, depth + n + 1) - depth;
  for (int x = r; x != 0; x = dad[x]) {
    used[x] = 1;
  }
  int ans = depth[r];
  FOR(i, 1, n + 1) {
    if (used[i]) {
      dfs3(i, 0, 0);
    }
  }
  printf("%d\n", ans + curr);
  FOR(i, 1, n + 1) {
    if (lmao == -1 && i != l && i != r) {
      lmao = i;
      break;
    }
  }
  printf("%d %d %d\n", l, r, lmao); 
  return 0;
}
