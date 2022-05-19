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

lli fen[N];
lli dp[N];
int a[N];
pair < lli, int > v[N];
int n;
int who[N];

void update (int idx, lli x) {
  while (idx <= n) {
    fen[idx] = max(fen[idx], x);
    idx += idx & -idx;
  }
}

lli query (int idx){
  lli ret = -2e18;
  while (idx > 0) {
    ret = max(ret, fen[idx]);
    idx -= idx & -idx;
  }
  return ret;
}

void solve () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    fen[i] = -2e18;
  }
  lli pref = 0;
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
    pref += a[i];
    v[i] = {pref, -i};
  }
  sort(v + 1, v + n + 1);
  FOR(i, 1, n + 1) {
    auto [ignore, x] = v[i];
    who[-x] = i; 
  }
  pref = 0;
  FOR(i, 1, n + 1) {
    dp[i] = dp[i - 1] + (a[i] > 0 ? 1 : a[i] < 0 ? -1 : 0);
    dp[i] = max(dp[i], i + query(who[i]));
    pref += a[i];
    if (pref > 0) {
      dp[i] = i;
    }
    update(who[i], -i + dp[i]);
  }
  printf("%lld\n", dp[n]);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
