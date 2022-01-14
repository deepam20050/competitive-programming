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

const int N = 2e5 + 5;

pii arr[N];
int n;
lli s;

bool f (int med) {
  vector < int > v;
  lli sum = 0;
  int cnt = 0;
  FOR(i, 0, n) {
    if (arr[i].S < med) {
      sum += arr[i].F;
    } else if (arr[i].F >= med) {
      sum += arr[i].F;
      ++cnt;
    } else {
      v.eb(arr[i].F);
    }
  }
  int need = max(0, (n + 1) / 2 - cnt);
  if (need > sz(v)) return 0;
  FOR(i, 0, sz(v)) {
    if (i < sz(v) - need) {
      sum += v[i];
    } else {
      sum += med;
    }
  }
  return sum <= s;
}

void solve () {
  scanf("%d %lld", &n, &s);
  FOR(i, 0, n) {
    int l, r;
    scanf("%d %d", &l, &r);
    arr[i] = {l, r};
  }
  sort(arr, arr + n);
  int l = 1, r = 1e9 + 500;
  FOR(i, 0, 30) {
    int m = l + r >> 1;
    if (f(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  printf("%d\n", l);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
