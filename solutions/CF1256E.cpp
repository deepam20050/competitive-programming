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
const int inf = 1e9;

int n;
pii p[N];
int dp[N];
int l[N];
int ans[N];

int main () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    int x;
    scanf("%d", &x);
    p[i] = {x, i};
  }
  sort(p + 1, p + n + 1);
  dp[1] = inf;
  dp[2] = inf;
  FOR(i, 3, n + 1) {
    dp[i] = dp[i - 3] + p[i].F - p[i - 2].F;
    l[i] = i - 2;
    if (i >= 4 && dp[i] > dp[i - 4] + p[i].F - p[i - 3].F) {
      dp[i] = dp[i - 4] + p[i].F - p[i - 3].F;
      l[i] = i - 3;
    }
    if (i >= 5 && dp[i] > dp[i - 5] + p[i].F - p[i - 4].F) {
      dp[i] = dp[i - 5] + p[i].F - p[i - 4].F;
      l[i] = i - 4;
    }
  }
  int id = 0;
  for (int i = n; i >= 1; --i) {
    int x = l[i];
    ++id;
    FOR(j, x, i + 1) {
      ans[p[j].S] = id;
    }
    i = l[i];
  }
  printf("%d %d\n", dp[n], id);
  FOR(i, 1, n + 1) {
    printf("%d ", ans[i]);
  }
  return 0;
}
