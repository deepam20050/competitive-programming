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

const int N = 1505;

int a[N];
map < int, vector < pii > > seg;

int main () {
  int n;
  scanf("%d", &n);
  FOR(i, 0, n) {
    scanf("%d", a + i);
  }
  FOR(r, 0, n) {
    int s = 0;
    for (int l = r; l >= 0; --l) {
      s += a[l];
      seg[s].eb(l, r);
    }
  }
  vector < pii > ans;
  for (const auto &[ignore, v] : seg) {
    int r = -1;
    vector < pii > tmp;
    for (auto [ll, rr] : v) {
      if (ll > r) {
        tmp.eb(ll, rr);
        r = rr;
      }
    }
    if (sz(tmp) > sz(ans)) {
      ans.clear();
      ans = tmp;
    }
  }
  printf("%d\n", sz(ans));
  for (auto &[l, r] : ans) {
    printf("%d %d\n", l + 1, r + 1);
  }
  return 0;
}
