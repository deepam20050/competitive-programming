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

const int N = 5005;

int n;
vector < int > c;
int dp[N][N];

int get (int x) {
  if (x < 0) x = 0;
  if (x > n + 1) x = n + 1;
  return x;
}

int f (int l, int r) {
  if (l == 0 && r == n + 1) return 0;
  int &ret = dp[l][r];
  if (ret != -1) return ret;
  if (c[l] == c[r]) {
    ret = 1 + f(get(l - 1), get(r + 1)); 
  } else {
    ret = 1;
    if (l == 0) {
      ret += f(l, r + 1);
    } else if (r == n + 1) {
      ret += f(l - 1, r);
    } else {
      ret += min(f(l - 1, r), f(l, r + 1));
    }
  }
  return ret;
}

int main () {
  scanf("%d", &n);
  c.resize(n + 1);
  c[0] = -1;
  FOR(i, 1, n + 1) scanf("%d", &c[i]);
  c.erase(unique(all(c)), c.end());
  n = sz(c) - 1;
  memset(dp, -1, sizeof dp);
  int ans = 2e9;
  FOR(i, 1, n + 1) {
    ans = min(ans, f(i - 1, i + 1));
  }
  printf("%d\n", ans);
  return 0;
}
