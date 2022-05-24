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

const int MOD = 1e9 + 7;

int add (int x, int y) {
  x += y;
  if (x >= MOD) {
    x -= MOD;
  }
  return x;
}

int main () {
  int a, b; scanf("%d %d", &a, &b);
  int ans = 0;
  FOR(m, 1, b) {
    int x = m * 1ll * a % MOD;
    lli lol = a * 1ll * (a + 1) >> 1ll;
    lol %= MOD;
    int k = b * 1ll * m % MOD;
    int y = k * lol % MOD;
    ans = add(ans, add(y, x));
  }
  printf("%d\n", ans);
  return 0;
}