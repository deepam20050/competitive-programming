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

int a[N];
lli sum[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k; cin >> n >> k;
  FOR(i, 1, n + 1) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int ans = -1, ans2 = 0;
  FOR(i, 1, n + 1) {
    sum[i] = sum[i - 1] + a[i];
    int l = 1, r = i;
    FOR(_, 0, 20) {
      int midx = l + r >> 1;
      if (1ll * a[i] * (i - midx + 1) - (sum[i] - sum[midx - 1]) <= k) {
        r = midx;
      } else {
        l = midx + 1;
      }
    }
    if (i - r + 1 > ans) {
      ans = i - r + 1;
      ans2 = a[i];
    }
  }
  cout << ans << " " << ans2 << '\n';
  return 0;
}