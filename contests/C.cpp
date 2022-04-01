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
const int LN = 26;
const int inf = 1e8;

char s[N];
int dp[N];
int nxt[N][LN];
int n;

int f (int i) {
  if (i >= n) {
    return 1;
  }
  auto &r = dp[i];
  if (r != -1) {
    return r;
  }
  r = n - i + 1;
  int c = s[i] - 'a';
  if (nxt[i][c] != -1) {
    int to = nxt[i][c];
    int add = to - i - 1;
    r = min(r, add + n - to);
    FOR(j, 0, LN) {
      if (nxt[to][j] != -1) {
        r = min(r, add + nxt[to][j] - to  - 1 + f(nxt[to][j]));
      }
    }
  }
  return r;
}

void solve () {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  FOR(j, 0, LN) {
    nxt[n + 1][j] = -1;
  }
  for (int i = n; i >= 0; --i) {
    dp[i] = -1;
    FOR(j, 0, LN) {
      nxt[i][j] = nxt[i + 1][j];
      if (i + 1 <= n && j + 'a' == s[i + 1]) {
        nxt[i][j] = i + 1;
      }
    }
  }
  int ans = n;
  FOR(i, 1, n + 1) {
    ans = min(ans, f(i) + i - 1);
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
