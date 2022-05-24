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

const int N = 2005;

int x[N], y[N];
lli from2[N];
int n, x1, y11, x2, y2;

lli sqr (int x) {
  return x * 1ll * x;
}

lli calc (int x, int y, int x0, int y0) {
  return sqr(x - x0) + sqr(y - y0);
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> x1 >> y11 >> x2 >> y2;
  vector < pair < lli, lli > > dist(n + 1);
  FOR(i, 0, n) {
    cin >> x[i] >> y[i];
    dist[i] = {calc(x[i], y[i], x2, y2), calc(x[i], y[i], x1, y11)};
  }
  dist[n] = {0, 0};
  lli ans = 2e18;
  for (auto [onei, twoi] : dist) {
    lli r1 = onei;
    lli r2 = 0;
    for (auto [onej, twoj] : dist) {
      if (onej > r1) {
        r2 = max(r2, twoj);
      }
    }
    ans = min(ans, r1 + r2);
  } 
  cout << ans << '\n';
  return 0;
}