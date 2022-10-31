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

vector < pii > g[N];
char s[123];
int n, m;
int used[N];
int one, zero;
bool bad;

void dfs (int u, int what) {
  one += what == 1;
  zero += what == 0;
  used[u] = what;
  for (auto [to, x] : g[u]) {
    int nxt = x;
    if (what == 1) {
      nxt = x ^ 1;
    } else {
      nxt = x;
    }
    if (used[to] != -1) {
      bad |= used[to] != nxt;
    } else {
      dfs(to, nxt);
    }
  }
}

void solve () {
  scanf("%d %d", &n, &m);
  FOR(i, 1, n + 1) {
    g[i].clear();
    used[i] = -1;
  }
  FOR(i, 0, m) {
    int a, b;
    scanf("%d %d %s", &a, &b, s);
    int c = s[0] == 'i';
    g[a].eb(b, c);
    g[b].eb(a, c);
  }
  int ans = 0;
  bad = 0;
  FOR(i, 1, n + 1) {
    if (bad || used[i] != -1) {
      continue;
    }
    one = 0;
    zero = 0;
    dfs(i, 0);
    ans += max(one, zero);
  }
  if (bad) {
    ans = -1;
  }
  printf("%d\n", ans);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
