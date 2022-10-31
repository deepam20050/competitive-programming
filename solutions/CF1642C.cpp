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

void solve () {
  int n, x;
  scanf("%d %d", &n, &x);
  multiset < lli > arr;
  FOR(i, 1, n + 1) {
    lli x;
    scanf("%lld", &x);
    arr.em(x);
  }
  int ans = 0;
  while (!arr.empty()) {
    auto val1 = *arr.begin();
    auto it = arr.lower_bound(val1 * x);
    if (it != arr.end() && *it == val1 * x) {
      arr.erase(it);
    } else {
      ++ans;
    }
    arr.erase(arr.begin());
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
