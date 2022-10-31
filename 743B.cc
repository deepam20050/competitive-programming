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
  int n; lli k; cin >> n >> k;
  lli l = 1, r = (1ll << n) - 1;
  for (int i = n; i >= 1; --i) {
    lli midx = l + r >> 1ll;
    if (k == midx) {
      cout << i << '\n';
      break;
    }  else if (k > midx) {
      l = midx + 1;
    } else {
      r = midx - 1;
    }
  }
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}