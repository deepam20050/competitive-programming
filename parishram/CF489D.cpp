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

const int N = 3005;

int n, m;
vector < int > g[N];
int cnt[N];

int main () {
  scanf("%d %d", &n, &m);
  FOR(i, 0, m) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    g[x].eb(y);
  }
  int ans = 0;
  FOR(i, 0, n) {
    memset(cnt, 0, sizeof cnt);
    for (auto to : g[i]) {
      for (auto x : g[to]) {
        ++cnt[x];
      }
    }
    FOR(j, 0, n) {
      if (i == j) continue;
      ans += cnt[j] * (cnt[j] - 1) >> 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
