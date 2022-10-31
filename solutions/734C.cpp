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

const int N = 2e5 + 5;

int a[N], b[N], c[N], d[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, k; cin >> n >> m >> k;
  int x, s; cin >> x >> s;
  FOR(i, 1, m + 1) {
    cin >> a[i];
  }
  FOR(i, 1, m + 1) {
    cin >> b[i];
  }
  FOR(i, 0, k) {
    cin >> c[i];
  }
  FOR(i, 0, k) {
    cin >> d[i];
  }
  lli ans = x * 1ll * n;
  FOR(i, 0, m + 1) {
    if (b[i] > s) continue;
    int idx = ub(d, d + k, s - b[i]) - d - 1;
    if (i > 0) {
      if (idx >= 0) {
        ans = min(ans, (n - c[idx]) * 1ll * a[i]);
      }
      ans = min(ans, n * 1ll * a[i]);
    }
    if (i == 0) {
      ans = min(ans, (n - c[idx]) * 1ll * x);
    }
  }
  cout << ans << '\n';
  return 0;
}