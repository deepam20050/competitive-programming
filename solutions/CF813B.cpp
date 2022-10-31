// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const lli N = 1e18;

vector < lli > pwx, pwy;
lli x, y, l, r;

void get_powers (lli p, vector < lli > &vec) {
  lli curr = 1;
  vec.eb(curr);
  while (1) {
    if (curr > N / p) break;
    curr *= p;
    if (curr <= r) vec.eb(curr);
    else break;
  }
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> x >> y >> l >> r;
  get_powers(x, pwx);
  get_powers(y, pwy);
  vector < lli > bad;
  for (auto &a : pwx) {
    for (auto &b : pwy) {
      if (a > r) continue;
      if (b > r - a) continue;
      if (a + b < l) continue;
      bad.eb(a + b);
    }
  }
  bad.eb(l - 1);
  bad.eb(r + 1);
  sort(all(bad));
  bad.erase(unique(all(bad)), bad.end());
  if (bad.empty()) {
    puts("0");
    return 0;
  }
  lli ans = 0;
  FOR(i, 1, sz(bad)) {
    ans = max(ans, bad[i] - bad[i - 1] - 1);
  }
  cout << ans << '\n';
  return 0;
}
