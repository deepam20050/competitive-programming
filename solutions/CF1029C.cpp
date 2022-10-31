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

const int N = 3e5 + 5;

int l[N], r[N];
int pl[N], pr[N], sl[N], sr[N];

int main () {
  int n; scanf("%d", &n);
  pr[0] = 2e9;
  sr[n + 1] = 2e9;
  FOR(i, 1, n + 1) {
    scanf("%d %d", l + i, r + i);
    pl[i] = max(pl[i - 1], l[i]);
    pr[i] = min(pr[i - 1], r[i]);
  }
  for (int i = n; i >= 1; --i) {
    sr[i] = min(sr[i + 1], r[i]);
    sl[i] = max(sl[i + 1], l[i]);
  }
  int ans = 0;
  FOR(i, 1, n + 1) {
    ans = max(ans, min(sr[i + 1], pr[i - 1]) - max(sl[i + 1], pl[i - 1]));
  }
  printf("%d\n", ans);
  return 0;
}
