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

const int N = 1005;

lli cnt[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  FOR(i, 0, m) {
    int y = i * i % m;
    cnt[y] += 1ll * (n / m) + (i > 0 && i <= n % m);
  }
  lli ans = 0;
  FOR(i, 1, m) {
    ans += cnt[i] * cnt[m - i];
  }
  ans += cnt[0] * cnt[0];
  cout << ans;
  return 0;
}