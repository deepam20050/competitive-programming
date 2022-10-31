#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 2e5 + 5;

lli p[N];
int a[N];
int n, s;
int ansl, ansr;

bool f (int len) {
  multiset < lli > vals;
  FOR(i, 1, len) {
    if (a[i] < 0) {
      vals.emplace(p[i] + s);
    }
  }
  int l = 1, r = len;
  while (l <= r && r <= n) {
    if (a[r] < 0) vals.emplace(p[r] + s);
    lli pk = p[l - 1];
    if (!vals.empty()) {
      if (*vals.begin() >= pk) {
        ansl = l;
        ansr = r;
        return 1;
      } 
    } else {
      ansl = l;
      ansr = r;
      return 1;
    }
    if (a[l] < 0) {
      vals.erase(vals.lower_bound(p[l] + s));
    }
    ++l;
    ++r;
  }
  return 0;
}

void solve () {
  scanf("%d %d", &n, &s);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
    p[i] = p[i - 1] + a[i];
  }
  int l = 0, r = n + 1;
  ansl = -1;
  ansr = -1;
  FOR(i, 0, 20) {
    int m = l + r >> 1;
    if (f(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  if (ansl == -1) {
    puts("-1");
    return;
  }
  printf("%d %d\n", ansl, ansr);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
