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
  int m; cin >> m;
  vector < vector < int > > a(2, vector < int > (m));
  for (int i = 0; i < 2; ++i) {
    for (auto &j : a[i]) {
      cin >> j;
    }
  }
  int sum1 = accumulate(all(a[0]), 0), sum2 = 0;
  int ans = 2e9;
  for (int i = 0; i < m; ++i) {
    sum1 -= a[0][i];
    ans = min(ans, max(sum1, sum2));
    sum2 += a[1][i];
  }
  cout << ans << '\n';
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}