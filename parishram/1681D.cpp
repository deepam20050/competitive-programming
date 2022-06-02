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
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

const int inf = 1e5;

map < lli, int > dp;
int n;

int f (lli x) {
  if (dp.count(x)) {
    return dp[x];
  }
  int bit = 0;
  lli tmp = x;
  int len = 0;
  while (tmp > 0) {
    int d = tmp % 10;
    bit |= 1 << d;
    tmp /= 10;
    ++len;
  }
  if (len == n) {
    return dp[x] = 0;
  }
  if (len > n) {
    return dp[x] = inf;
  }
  dp[x] = inf;
  FOR(y, 1, 10) {
    if (!(bit >> y & 1)) continue;
    if (x * y > x) {
      dp[x] = min(dp[x], 1 + f(x * y));
    }
  }
  return dp[x];
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  lli x; cin >> n >> x;
  int ans = f(x);
  cout << (ans >= inf ? -1 : ans) << '\n';
  return 0;
}