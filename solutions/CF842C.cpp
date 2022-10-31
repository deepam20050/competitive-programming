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
int ans[N];
int cnt[N];
int a[N];
vector < int > divs;

void dfs1 (int u, int gg, int pr = -1) {
  ans[u] = gg;
  for (auto to : g[u]) {
    if (to != pr) {
      dfs1(to, gcd(gg, a[to]), u);
    }
  }
}

void dfs2 (int u, int depth, int pr = -1) {
  FOR(i, 0, sz(divs)) {
    cnt[i] += a[u] % divs[i] == 0;
    if (cnt[i] == depth - 1) {
      ans[u] = max(ans[u], divs[i]);
    }
  }
  for (auto &to : g[u]) {
    if (to != pr) {
      dfs2(to, depth + 1, u);
    }
  }
  FOR(i, 0, sz(divs)) {
    cnt[i] -= a[u] % divs[i] == 0;
  }
}

int main () {
  int n;
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
  }
  FOR(i, 1, n) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].eb(y);
    g[y].eb(x);
  }
  dfs1(1, 0);
  for (int i = 1; i * 1ll * i <= a[1]; ++i) {
    if (a[1] % i == 0) {
      divs.eb(i);
      divs.eb(a[1] / i);
    }
  }
  ans[1] = a[1];
  dfs2(1, 1);
  FOR(i, 1, n + 1) {
    printf("%d ", ans[i]);
  }
  return 0;
}
