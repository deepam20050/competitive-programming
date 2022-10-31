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

const int N = 1 << 20;

int cnt[2][N];

int main () {
  int n; scanf("%d", &n);
  int p = 0;
  lli ans = 0;
  ++cnt[0][0];
  FOR(i, 1, n + 1) {
    int x; scanf("%d", &x);
    p ^= x;
    ans += cnt[i & 1][p];
    ++cnt[i & 1][p];
  }
  printf("%lld\n", ans);
  return 0;
}