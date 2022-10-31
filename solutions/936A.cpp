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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  lli k, d, t; cin >> k >> d >> t;
  lli period = 0;
  if (k <= d) {
    period = d;
  } else {
    period = ((k + d - 1) / d) * d;
  }
  lli cooking = k + period;
  t += t;
  lli num = t / cooking;
  lli carry = t - num * cooking;
  if (carry > 2 * k) {
    cout << fixed << setprecision(15) << num * period + carry - k << '\n';
  } else {
    cout << fixed << setprecision(15) << num * period + carry / 2.0 << '\n';
  }
  return 0;
}