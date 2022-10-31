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

const int MAXN = 2e6 + 5;
const int inf = 1e9;

bool not_prime[MAXN];
vector < tuple < int, int, int > > edges;

void sieve () {
  not_prime[0] = not_prime[1] = 1;
  for (int i = 2; i * i < MAXN; ++i) {
    if (!not_prime[i]) {
      for (int j = i + i; j < MAXN; j += i) {
        not_prime[j] = 1;
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  sieve();
  int n, m; cin >> n >> m;
  int ans = 0;
  FOR(i, 2, MAXN) {
    if (not_prime[i]) continue;
    int x = i - (n - 1);
    if (0 <= x && x <= (n - 1) * 1ll * (inf - 1)) {
      ans = i;
      FOR(j, 2, n + 1) {
        int req = 1 + max(0, x);
        x -= req;
        edges.eb(j - 1, j, req);
      }
      break;
    }
  }
  for (int i = 1; i <= n && sz(edges) < m; ++i) {
    FOR(j, i + 2, n + 1) {
      if (sz(edges) == m) break;
      edges.eb(i, j, inf);
    }
  }
  cout << ans << " " << ans << '\n';
  for (auto [a, b, c] : edges) {
    cout << a << " " << b << " " << c << '\n';
  }
  return 0;
}