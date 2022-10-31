// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 1e5 + 5;

vector < int > g[N];
bitset < N > yes;

int f_min;

void dfs (int u, int pr = -1, int d = 0) {
  for (auto &to : g[u]) {
    if (to != pr) {
      dfs(to, u, d + 1);
    }
  }
  if (sz(g[u]) == 1) {
    f_min = max(f_min, d & 1 ? 3 : 1);
  }
}

int main () {
  int n;
  scanf("%d", &n);
  FOR(i, 1, n) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].eb(b);
    g[b].eb(a);
  }
  int root = 1;
  int e = n - 1, l = 0;
  FOR(i, 1, n + 1) {
    if (sz(g[i]) == 1) {
      root = i;
      ++l;
      for (auto &to : g[i]) yes[to] = 1;
    }
  }
  dfs(root);
  printf("%d %d\n", f_min, e - l + (int)yes.count());
  return 0;
}