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

void test_case() {
  int n; lli h; cin >> n >> h;
  vector < int > a(n);
  for (auto &e : a) {
    cin >> e;
  }
  function < bool (lli) > f = [&] (lli k) {
    lli l = a[0], r = a[0] + k - 1;
    lli tot = 0;
    for (int i = 1; i < n; ++i) {
      if (r >= a[i]) {
        r = a[i] + k - 1;
      } else {
        tot += r - l + 1;
        l = a[i];
        r = a[i] + k - 1;
      }
    }
    tot += r - l + 1;
    return tot >= h;
  };
  lli l = 1, r = h + 1;
  for (int i = 0; i < 60; ++i) {
    lli midx = l + r >> 1ll;
    if (f(midx)) {
      r = midx;
    } else {
      l = midx;
    }
  }
  cout << r << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}