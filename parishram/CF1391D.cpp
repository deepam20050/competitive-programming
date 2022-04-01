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

const int N = 5e5 + 5;
const int inf = 1e9;

int dp[N][1 << 3];
int n, m;
char s[N];
int a[3][N];

int get (int x, int b) {
  return x >> b & 1;
}

inline bool check (int mask1, int mask2) {
  FOR(i, 0, n - 1) {
    int x = get(mask1, i) + get(mask1, i + 1) + get(mask2, i) + get(mask2, i + 1);
    if (x % 2 == 0) {
      return 0;
    }
  }
  return 1;
}

int main () {
  scanf("%d %d", &n, &m);
  if (n >= 4 && m >= 4) {
    puts("-1");
    return 0;
  }
  if (n == 1 || m == 1) {
    puts("0");
    return 0;
  }
  FOR(i, 0, n) {
    scanf("%s", s);
    FOR(j, 0, m) {
      a[i][j] = s[j] - '0';
    }
  }
  FOR(mask, 0, 1 << n) {
    dp[m][mask] = 0;
  }
  for (int c = m - 1; c >= 0; --c) {
    FOR(mask1, 0, 1 << n) {
      dp[c][mask1] = inf;
      FOR(mask2, 0, 1 << n) {
        if (!check(mask1, mask2)) {
          continue;
        }
        int x = 0;
        FOR(j, 0, n) {
          x += (mask1 >> j & 1) ^ a[j][c];
        }
        x += dp[c + 1][mask2];
        dp[c][mask1] = min(dp[c][mask1], x);
      }
    }
  }
  int ans = inf;
  FOR(mask, 0, 1 << n) {
    ans = min(ans, dp[0][mask]);
  }
  printf("%d\n", ans);
  return 0;
}
