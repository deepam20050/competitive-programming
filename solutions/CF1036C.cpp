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

vector < lli > vals;

void solve (int pos, int cnt, lli num) {
  if (pos == 18) {
    vals.eb(num);
    return;
  }
  solve(pos + 1, cnt, num * 10);
  if (cnt == 3) return;
  FOR(i, 1, 10) {
    solve(pos + 1, cnt + 1, num * 10 + i);
  }
}

int main () {
  solve(0, 0, 0);
  vals.eb(1e18);
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    lli l, r;
    scanf("%lld %lld", &l, &r);
    int x = upper_bound(all(vals), r) - vals.begin();
    int y = lower_bound(all(vals), l) - vals.begin();
    printf("%d\n", x - y);
  }
  return 0;
}
