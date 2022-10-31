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

const int N = 1e6 + 5;

char s[N];
int pref[N];
int dp[N];
int n, k;

int get (int x) {
  return x > n ? n + 1 : x;
}

void solve () {
  scanf("%d %d", &n, &k);
  scanf("%s", s + 1);
  FOR(i, 0, n + 2) {
    dp[i] = 0;
  }
  FOR(i, 1, n + 1) {
    pref[i] = pref[i - 1] + (s[i] == '1');
  }
  pref[n + 1] = pref[n];
  int ans = pref[n];
  for (int i = n; i >= 1; --i) {
    dp[i] = min(dp[get(i + k)] + pref[get(i + k - 1)] - pref[i] + (s[i] == '0'), (s[i] == '0') + pref[n] - pref[i]); 
    int x = min(dp[get(i + k)] + pref[i - 1] + (s[i] == '0') + pref[get(i + k - 1)] - pref[i], pref[n] - (s[i] == '1'));
    ans = min(ans, x);
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
