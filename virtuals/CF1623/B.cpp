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

const int N = 1005;

int n;
set < int > lft[N], rgt[N];
pii lrs[N];

void solve () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    lft[i].clear();
    rgt[i].clear();
  }
  FOR(i, 0, n) {
    int l, r;
    scanf("%d %d", &l, &r);
    lft[l].em(r);
    rgt[r].em(l);
    lrs[i] = {l, r};
  }
 //  sort(lrs, lrs + n);
  FOR(i, 0, n) {
    auto [l, r] = lrs[i];
    int ans = -1;
    FOR(d, l, r + 1) {
      bool ok1 = (l > d - 1);
      bool ok2 = (l <= d - 1 && lft[l].find(d - 1) != lft[l].end());
      bool ok3 = (d + 1 > r);
      bool ok4 = (d + 1 <= r && rgt[r].find(d + 1) != rgt[r].end());
      if ((ok1 || ok2) && (ok3 || ok4)) {
        ans = d;
        break;
      }
    }
    printf("%d %d %d\n", l, r, ans);
  }
  puts("");
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
