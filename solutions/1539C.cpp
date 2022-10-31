#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
  #include "../algo/debug.hpp"
#else
  #define debug(...)
#endif
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back

using lli = long long;
using pii = pair < int, int >;

const int N = 2e5 + 5;

lli a[N];
int n;
lli k, x;
  
void test_case() {
  cin >> n >> k >> x;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  a[n] = 4e18;
  vector < vector < lli > > seg;
  vector < lli > v = {a[0]};
  for (int i = 1; i <= n; ++i) {
    if (a[i] - a[i - 1] <= x) {
      v.emplace_back(a[i]);
    } else {
      seg.emplace_back(v);
      v = {a[i]};
    }
  }
  vector < tuple < lli, int, int > > comps;
  for (int i = 1; i < sz(seg); ++i) {
    auto l = seg[i - 1].back(), r = seg[i].front();
    comps.emplace_back(1ll * (r - l + x - 1) / x - 1, i, i - 1);
  }
  int ans = sz(seg);
  sort(all(comps));
  for (auto [c, u, v] : comps) {
    if (k >= c) {
      k -= c;
      --ans;
    }
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}