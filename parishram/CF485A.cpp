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

const int N = 1e5 + 5;

int a, m; 
int dp[N];
int used[N];

int f (int x) {
  if (used[x]) {
    return 0;
  }
  if (dp[x] != -1) {
    return dp[x];
  }
  used[x] = 1;
  return dp[x] = f((x + x) % m);
}

int main () {
  scanf("%d %d", &a, &m);
  memset(dp, -1, sizeof dp);
  dp[0] = 1;
  dp[m] = 1;
  f(a % m) ? puts("Yes") : puts("No");
  return 0;
}
