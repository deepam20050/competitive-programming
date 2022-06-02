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

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  lli n, a, b, p, q; cin >> n >> a >> b >> p >> q;
  lli rb = n / lcm(a, b);
  lli r = n / a - rb;
  lli blu = n / b - rb;
  lli ans = r * 1ll * p + blu * 1ll * q + rb * 1ll * max(p, q);
  cout << ans << '\n';
  return 0;
}