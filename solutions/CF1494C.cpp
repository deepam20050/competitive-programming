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

const int inf = 2e9;

vector < int > v[2], good[2], nice, vals;
int n, m;

int get () {
  vector < int > suff(sz(nice) + 1);
  for (int i = sz(nice) - 1; i >= 0; --i) {
    suff[i] = suff[i + 1] + (int)binary_search(all(vals), nice[i]);
  }
  FOR(i, 0, sz(vals)) {
    vals[i] -= i;
  }
  int ans = suff[0];
  FOR(i, 0, sz(nice)) {
    int k = upper_bound(all(vals), nice[i]) - vals.begin();
    int j = lower_bound(all(nice), nice[i] + k) - nice.begin();
    ans = max(ans, j - i + suff[j]);
  }
  return ans;
}

void solve () {
  scanf("%d %d", &n, &m);
  v[0].clear();
  v[1].clear();
  good[0].clear();
  good[1].clear();
  FOR(i, 0, n) {
    int a;
    scanf("%d", &a);
    if (a > 0) {
      v[0].eb(a);
    } else {
      v[1].eb(-a);
    }
  }
  FOR(i, 0, m) {
    int b;
    scanf("%d", &b);
    if (b > 0) {
      good[0].eb(b);
    } else {
      good[1].eb(-b);
    }
  }
  reverse(all(v[1]));
  reverse(all(good[1]));
  int ans = 0;
  FOR(i, 0, 2) {
    if (v[i].empty() || good[i].empty()) {
      continue;
    }
    vals = v[i];
    nice = good[i];
    ans += get();
  }
  printf("%d\n", ans);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
