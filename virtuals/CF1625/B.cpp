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

const int N = 150'005;

bitset < N > used;
vector < int > g[N];
int n;
int a[N];

void solve () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
    used[a[i]] = 0;
    g[a[i]].clear();
  }
  FOR(i, 1, n + 1) {
    g[a[i]].eb(i);
  }
  int ans = 0;
  FOR(i, 1, n + 1) {
    if (used[a[i]]) continue;
    int x = a[i];
    FOR(j, 1, sz(g[x])) {
      ans = max(ans, g[x][j - 1] + n - g[x][j]); 
    }
    used[a[i]] = 1; 
  }
  if (!ans) ans = -1;
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
