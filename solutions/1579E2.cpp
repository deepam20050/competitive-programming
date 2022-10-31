#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
template < typename T > using ordered_set = tree < T, null_type, less < T > , rb_tree_tag,tree_order_statistics_node_update >;
/* ordered_set < T > s -> doesn't work well with pii
 * s.order_of_key(x) -> # of elements in s less than x
 * s.find_by_order(x) -> returns x^th smallest number in s (0 - based)
 */

void solveTestCase () {
  ordered_set < pii > s;
  int n; scanf("%d", &n);
  lli ans = 0;
  FOR(i, 0, n) {
    int x; scanf("%d", &x);
    int small = s.order_of_key(mp(x, -1));
    int big = i - s.order_of_key(mp(x, n));
    ans += min(small, big);
    s.insert(mp(x, i));
  }
  printf("%lld\n", ans);
}

int main () {
  int _tc; scanf("%d", &_tc);
  while (_tc--) {
    solveTestCase();
  }
  return 0;
}