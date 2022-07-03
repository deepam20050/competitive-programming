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

const lli inf = 1e18;

void test_case() {
  vector < lli > mini(6, inf), maxi(6, -inf);
  mini[0] = maxi[0] = 1;
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    for (int j = min(5, i); j >= 1; --j) {
      lli p1 = maxi[j - 1] * x;
      lli p2 = mini[j - 1] * x;
      mini[j] = min({mini[j], p1, p2});
      maxi[j] = max({maxi[j], p1, p2});
    }
  }
  cout << maxi[5] << '\n';
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