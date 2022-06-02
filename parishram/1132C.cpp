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

const int N = 5005;

int p1[N], p2[N];
int l[N], r[N];
int n, q;

int solve (int idx) {
  memset(p1, 0, sizeof p1);
  memset(p2, 0, sizeof p2);
  FOR(i, 1, q + 1) {
    if (i != idx) {
      ++p1[l[i]];
      --p1[r[i] + 1];
    }
  }
  FOR(i, 1, n + 1) {
    p1[i] += p1[i - 1];
    p2[i] = p2[i - 1] + (p1[i] == 1 ? 1 : 0);
  }
  int ans = 1e9;
  FOR(i, 1, q + 1) {
    if (i != idx) {
      ans = min(ans, p2[r[i]] - p2[l[i] - 1]);
    }
  }
  ans *= -1;
  FOR(i, 1, n + 1) {
    ans += p1[i] > 0;
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> q;
  FOR(i, 1, q + 1) {
    cin >> l[i] >> r[i];
  }
  int ans = 0;
  FOR(i, 1, q + 1) {
    ans = max(ans, solve(i));
  }
  cout << ans << '\n';
  return 0;
}