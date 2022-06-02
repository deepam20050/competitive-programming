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

const int N = 31;

lli c[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; lli L; cin >> n >> L;
  FOR(i, 0, n) {
    cin >> c[i];
  }
  FOR(i, 1, n) {
    c[i] = min(c[i - 1] * 2, c[i]);
  }

  FOR(i, n, N) {
    c[i] = c[i - 1] * 2;
  }
  lli ans = 0;
  for (int i = N - 1; i >= 0; --i) {
    if (L >> i & 1ll) {
      ans += c[i];
    }
  }
  lli sum = 0;
  for (int i = N - 1; i >= 0; --i) {
    if (L >> i & 1ll) {
      sum += c[i];
      continue;
    }
    ans = min(ans, sum + c[i]);
  }
  cout << ans << '\n';
  return 0;
}