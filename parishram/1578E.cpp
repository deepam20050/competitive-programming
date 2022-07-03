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

lli get (lli x, lli y) {
  return (lli)(x + y - 1) / (lli)y;
}

void test_case() {
  int n, k; cin >> n >> k;
  lli total = 1ll << n;
  total -= 1;
  lli cnt = 0, sum = 0;
  for (int i = 0; i < n; ++i) {
    lli x = 1ll << i;
    if (k < x) {
      break;
    } else {
      ++cnt;
      sum += x;
    }
  }
  total -= sum;
  lli ans = get(total, k);
  cout << ans + cnt << '\n';
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